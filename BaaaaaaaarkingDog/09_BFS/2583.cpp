#include <bits/stdc++.h>
using namespace std;

int m, n, k; // 세로, 가로
int board[102][102];
int vis[102][102];
queue<pair<int, int> > q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ret;
vector<int> arr;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = y1; i < y2; i++)
            for (int j = x1; j < x2; j++)
                board[i][j] = 1; // 이런 곳이 헷갈린다. 2차원의 파싱.
    }

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << board[i][j] << ' ';
    //     cout << '\n';
    // } // 뒤집혔을 뿐 잘 파싱됨. 가로,세로는 잘 맞았다.

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1 || vis[i][j] == 1)
                continue;
            vis[i][j] = 1;
            q.push({i, j});
            ret = 1;

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (board[nx][ny] == 1 || vis[nx][ny] == 1)
                        continue;

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                    ret++;
                }
            }

            // cout << ret << ' ';
            arr.push_back(ret);
        }

    cout << arr.size() << '\n';
    sort(arr.begin(), arr.end());
    for (int n : arr)
        cout << n << ' ';
}

/*
* 항상 좌표계가 헷갈린다. -> 가로, 세로만 맞다면 방향은 틀려도 답엔 영향이 없을것. 지금도 가로,세로만 맞고 뒤집혀있다.
*/