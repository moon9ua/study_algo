#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[11];

void func(int idx, int min)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = min; i <= n; i++)
    {
        arr[idx] = i;
        func(idx + 1, i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0, 1);
}
