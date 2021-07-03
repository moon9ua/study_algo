/*
// 유니온 파인드
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int parent[204];

int my_find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = my_find(parent[x]);
}

void my_union(int x, int y)
{
    x = my_find(x);
    y = my_find(y);
    if (y < x)
        parent[x] = y;
    else
        parent[y] = x;
}

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            if (computers[i][j] == 1)
                my_union(i, j);
        }
    }

    vector<int> ret(n);
    for (int i = 0; i < n; i++)
        ret[i] = my_find(i); // 양방향이 아니라..? 양방향이면 안해줘도 됨.

    sort(ret.begin(), ret.end());
    return unique(ret.begin(), ret.end()) - ret.begin();
}
*/

// bfs
#include <string>
#include <vector>
#include <queue>

using namespace std;

int vis[204];

int solution(int n, vector<vector<int>> computers) {
    queue<int> q;
    int ret = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i]) continue;
        q.push(i);
        vis[i] = 1;
        ret++;
        while (q.size())
        {
            auto cur = q.front(); q.pop();
            for (int j = 0; j < n; j++)
            {
                if (cur == j) continue;
                if (computers[cur][j] == 0 || vis[j] == 1) continue;
                q.push(j);
                vis[j] = 1;
            }
        }
    }
    return ret;
}

/*
// dfs
#include <string>
#include <vector>

using namespace std;

int vis[204];

void dfs(int cur, int n, vector<vector<int>>& computers)
{
    vis[cur] = 1;

    for (int i = 0; i < n; i++)
    {
        if (computers[cur][i] && vis[i] == 0)
            dfs(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int ret = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, n, computers);
            ret++;
        }
    }
    return ret;
}
*/