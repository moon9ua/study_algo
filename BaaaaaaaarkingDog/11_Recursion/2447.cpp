#include <bits/stdc++.h>
using namespace std;

// int board[10005][10005]; // 범위가 괜찮을까? ❌ 256MB 초과.
int board[7000][7000]; // ⭕️ 이 정도로 줄여야 한다. 근데 이 범위 내로 문제가 해결되는지는 계산 안해보고 풀었음.

void func(int x, int y, int n)
{
    int new_n = n / 3;
    if (new_n == 0)
    {
        board[x][y] = 1;
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                continue;
            func(x + i * new_n, y + j * new_n, new_n); // ❌ x,y 더해주는걸 빼서 헤맸었다.
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    func(0, 0, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }
}

/*
* 바로 출력할 수가 있나? 저장해야 한다면 그게 범위 내로 가능한가?
*/