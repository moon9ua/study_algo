#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
// int vis[10];

void func(int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        // if (vis[i] == 0)
        // {
        arr[idx] = i;
        // vis[i] = 1;
        func(idx + 1);
        // vis[i] = 0;
        // }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}
