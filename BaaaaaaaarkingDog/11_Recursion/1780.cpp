#include <bits/stdc++.h>
using namespace std;

// int mn, zr, pl;
int ret[3];
int board[3000][3000];

void func(int n, int x, int y)
{
    int color = board[x][y];
    bool end = true;

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (board[i][j] != color)
            {
                end = false;
                break;
            }
        }
        if (end == false)
            break;
    }

    if (end)
    {
        ret[color + 1] += 1;
        return;
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            func(n / 3, x + n / 3 * i, y + n / 3 * j);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << pow(3, 7); // 범위 확인

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    func(n, 0, 0);

    for (int n : ret)
        cout << n << '\n';
}

// 1992번과 완전 똑같고 약간 쉬운 유형.