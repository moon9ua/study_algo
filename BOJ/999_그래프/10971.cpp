#include <bits/stdc++.h>
using namespace std;

int n;
int cost[15][15];
int min_cost;
int vis[15];

void dfs(int idx, int cur, int sum, int start)
{
    if (idx == n)
    {
        if (cost[cur][start] == 0)
            return;
        sum += cost[cur][start];
        min_cost = sum < min_cost ? sum : min_cost;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0 && cost[cur][i] > 0)
        {
            vis[i] = 1;
            dfs(idx + 1, i, sum + cost[cur][i], start);
            vis[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    min_cost = INT_MAX;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    for (int i = 0; i < n; i++)
    {
        vis[i] = 1;
        dfs(1, i, 0, i);
        vis[i] = 0;
    }

    cout << min_cost;
}

// 완전탐색
// 백트래킹