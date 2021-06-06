#include <bits/stdc++.h>
using namespace std;

int n, k;
int board[10][2]; // 학년,성별
int ret;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    while (n--)
    {
        int s, y;
        cin >> s >> y;

        board[y][s] += 1;
    }

    for (int i = 1; i <= 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ret += board[i][j] / k;
            if (board[i][j] % k)
                ret += 1;
            // ret += board[i][j] % k;
        }
    }

    cout << ret;
}
