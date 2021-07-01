#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int solution(int N, vector<vector<int> > road, int K) {
    vector<pii> g[N + 1];
    for (auto& a : road)
    {
        g[a[0]].push_back({ a[1],a[2] });
        g[a[1]].push_back({ a[0],a[2] });
    }

    const int inf = 1e9;
    vector<int> dist(N + 1, inf);

    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({ 0, 1 });
    while (q.size())
    {
        auto cur = q.top(); q.pop();
        int node = cur.second; // 1
        int time = cur.first; // 0
        if (dist[node] == inf)
        {
            dist[node] = time;
            for (auto& a : g[node])
                q.push({ a.second + time,a.first });
        }
    }

    int ret = 0;
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] <= K)
            ret++;
    }
    return ret;
}

// 출발은 1번. K시간 이내 가능