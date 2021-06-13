#include <bits/stdc++.h>
using namespace std;

int n;
int in, mx;
vector<int> arr;
float ret;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) // 다른 방법 없나?
    {
        cin >> in;
        arr.push_back(in);
        mx = max(mx, in);
    }

    for (int n : arr)
    {
        // cout << "n:" << n << '\n';
        // cout << "mx:" << mx << '\n';
        // cout << "ret:" << (float)n / mx * 100 << '\n'; // 직접 찍어보는게 최고!
        ret += (float)n / mx * 100;
    }
    cout << ret / arr.size();
}
