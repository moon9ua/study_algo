#include<vector>
#include <queue>
using namespace std;

int vis[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();

    queue<pair<int, int>> q;

    fill(&vis[0][0], &vis[n][m - 1], -1);
    q.push({ 0,0 });
    vis[0][0] = 1;

    while (!q.empty())
    {
        auto cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (maps[nx][ny] == 0 || vis[nx][ny] != -1)
                continue;

            q.push({ nx,ny });
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }

    return vis[n - 1][m - 1];
}

// 제일 간단하게 bfs 구현하는 방법이 뭐지?