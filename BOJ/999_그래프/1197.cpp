// 프림 알고리즘
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

bool vis[10004];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e;
    cin >> v >> e;

    vector<pii> graph[v + 1];
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    vis[1] = 1;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (auto& a : graph[1])
        pq.push({ a.second, a.first });

    int ret = 0;
    while (pq.size())
    {
        auto [cost, node] = pq.top();
        pq.pop();

        if (vis[node])
            continue;
        vis[node] = 1;
        ret += cost;

        for (auto& a : graph[node])
            pq.push({ a.second, a.first });
    }

    cout << ret;
}

// 첫째줄: 정점수, 간선수
// 다음 e개의 줄: a정점, b정점, c가중치
// 정점은 1~v
