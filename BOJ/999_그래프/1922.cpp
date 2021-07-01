#include <vector>
#include <queue> // pq 포함?
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

bool vis[1004];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m; // 엔터 있어도 된다!

    vector<pii> graph[n + 1];
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0, 1 });

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
