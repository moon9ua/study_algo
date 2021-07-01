#include <bits/stdc++.h>
using namespace std;

int ns[500003];
// int ms[500003];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ns[i];
    sort(ns, ns + n);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int target;
        cin >> target;

        bool ret = binary_search(ns, ns + n, target);
        cout << ret << ' ';
    }
}
