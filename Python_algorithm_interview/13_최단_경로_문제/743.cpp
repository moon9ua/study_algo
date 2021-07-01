typedef pair<int, int> pii;

class Solution
{
public:
    int networkDelayTime(vector<vector<int> > &times, int n, int k)
    {
        vector<pii> graph[n + 1];
        for (auto &a : times)
            graph[a[0]].emplace_back(a[1], a[2]);

        priority_queue<pii, vector<pii>, greater<pii> > q;
        q.emplace(0, k);

        const int inf = 1e9; // 왜 이값?
        vector<int> dist(n + 1, inf);

        while (q.size())
        {
            int time = q.top().first;
            int node = q.top().second;
            q.pop();

            if (dist[node] == inf)
            {
                dist[node] = time;
                for (auto &a : graph[node])
                {
                    int v = a.first, w = a.second;
                    q.emplace(time + w, v);
                }
            }
        }

        int ret = *max_element(dist.begin() + 1, dist.end());
        return ret == inf ? -1 : ret;
    }
};