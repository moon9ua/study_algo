/*
// 1. bfs
class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    int numIslands(vector<vector<char>>& grid) {
        stack<pair<int, int> > s;
        int m = grid[0].size();
        int n = grid.size();
        int ret = 0;
        
        int vis[n][m];
        fill(&vis[0][0], &vis[n - 1][m], 0); // 잘 되나?
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 1 || grid[i][j] == '0')
                    continue;
                
                s.push({i,j});
                vis[i][j] = 1;
                ret++;

                while (!s.empty())
                {
                    auto cur = s.top(); s.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        if (vis[nx][ny] == 1 || grid[nx][ny] == '0')
                            continue;

                        s.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        
        return ret;
    }
};
*/

// 2. dfs 재귀
class Solution
{
public:
    int m, n, ret;

    void dfs(int x, int y, vector<vector<char> > &grid)
    {
        if (x < 0 || x >= n || y < 0 || y >= m ||
            grid[x][y] == '0')
            return;

        grid[x][y] = '0';
        dfs(x + 1, y, grid);
        dfs(x, y + 1, grid);
        dfs(x - 1, y, grid);
        dfs(x, y - 1, grid);
    };

    int numIslands(vector<vector<char> > &grid)
    {
        m = grid[0].size();
        n = grid.size();
        ret = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    ret++;
                }
            }
        }
        return ret;
    }
};