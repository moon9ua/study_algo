#include <string>
#include <vector>
// #include <priority_queue>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int solution(int n, vector<vector<int> > edge)
{
    vector<int> graph[n + 1];
    for (auto &a : edge)
    {
        graph[a[0]].push_back(a[1]);
        graph[a[1]].push_back(a[0]);
    }

    const int inf = 1e9;
    vector<int> dist(n + 1, inf);

    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push({0, 1});

    while (q.size())
    {
        int time = q.top().first, node = q.top().second;
        q.pop();
        if (dist[node] == inf)
        {
            dist[node] = time;
            for (auto a : graph[node])
                q.push({time + 1, a});
        }
    }

    int mx = 0;
    int ret = 0;
    for (auto a : dist)
    {
        if (a != inf && a != mx)
        {
            mx = max(mx, a);
            if (mx == a)
                ret = 0;
        }
        if (mx == a)
            ret++;
    }

    return ret;
}