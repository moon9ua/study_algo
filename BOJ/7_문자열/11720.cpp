#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int ret = 0;
    for (char c : s)
        ret += c - '0';

    cout << ret;
}
