#include <bits/stdc++.h>
using namespace std;

int board[1005][1005];
int days[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n;
int day;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    queue<pair<int, int> > q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                days[i][j] = 0;
                q.push({i, j});
            }
            // else
            else if (board[i][j] == 0) // ❗️ 비어있는 곳만 가게끔.
                days[i][j] = -1;
        }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (days[nx][ny] != -1)
                continue;

            days[nx][ny] = days[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            // if (board[i][j] == 0 && days[i][j] == -1)
            if (days[i][j] == -1) // ❗️ 비어있는 곳만 가게끔 했으므로, 이렇게 수정 가능.
            {
                cout << -1 << '\n';
                return (0);
            }
            day = max(day, days[i][j]);
        }

    cout << day << '\n';
}

/*
* 시작점이 여러곳인 경우를 생각 못해서 틀림.
*/