#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[11];
int vis[11];

void func(int idx, int num)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = num; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            arr[idx] = i;
            vis[i] = 1;
            func(idx + 1, i + 1); // 💡 배열의 숫자가 뒤로 갈수록 커지게 하면 된다.
            vis[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0, 1);
}
