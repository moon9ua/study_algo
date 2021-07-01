#include <bits/stdc++.h>
using namespace std;

int rsp[3][53];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<char, int> hash;
    hash['R'] = 0;
    hash['S'] = 1;
    hash['P'] = 2;

    int r, n;
    cin >> r;
    string my;
    cin >> my;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < r; j++)
            rsp[hash[str[j]]][j]++;
    }

    int point = 0;
    int mx = 0;
    for (int i = 0; i < r; i++)
    {
        point += rsp[hash[my[i]]][i];
        point += rsp[(hash[my[i]] + 1) % 3][i] * 2;

        int rsp_mx = 0;
        for (int j = 0; j < 3; j++)
        {
            int tmp = 0;
            tmp += rsp[j][i];
            tmp += rsp[(j + 1) % 3][i] * 2;
            rsp_mx = max(rsp_mx, tmp);
        }
        mx += rsp_mx;
    }

    cout << point << '\n';
    cout << mx << '\n';
}

// 이기면 2점, 비기면 1점