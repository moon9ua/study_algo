#include <bits/stdc++.h>
using namespace std;

int ns[100004];
int ms[100004];

int main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ns[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> ms[i];

    sort(ns, ns + n);
    for (int i = 0; i < m; i++)
    {
        bool b = binary_search(ns, ns + n, ms[i]);
        cout << b << '\n';
    }
}
