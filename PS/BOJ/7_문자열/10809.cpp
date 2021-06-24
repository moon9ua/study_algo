#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int al[30];
    fill(al, al + 30, -1);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (al[s[i] - 'a'] == -1)
            al[s[i] - 'a'] = i;
    }

    for (int i = 'a'; i <= 'z'; i++)
        cout << al[i - 'a'] << ' ';
}
