#include <vector>
#include <queue>

using namespace std;

int vis[104][104];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

typedef pair<int, int> pii;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int cnt = 0;
    int max_area = 0;

    queue<pii> q;
    int area, color;

    fill(&vis[0][0], &vis[103][104], 0); // 이거 안해서 틀렸었음.

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (picture[i][j] == 0 || vis[i][j] == 1)
                continue;

            q.push({ i,j });
            vis[i][j] = 1;
            cnt++;
            area = 0;
            while (q.size())
            {
                auto cur = q.front(); q.pop();
                color = picture[cur.first][cur.second];
                area++;
                for (int a = 0; a < 4; a++)
                {
                    int nx = cur.first + dx[a];
                    int ny = cur.second + dy[a];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (picture[nx][ny] != color || vis[nx][ny] == 1)
                        continue;

                    q.push({ nx, ny });
                    vis[nx][ny] = 1;
                }
            }
            max_area = max(max_area, area);
        }
    }

    return { cnt, max_area };
}
