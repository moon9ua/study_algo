class Solution {
public:
    typedef pair<int, int> pii;
    typedef array<int, 3> arr;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pii> graph[n];
        for (auto& a : flights)
            graph[a[0]].push_back({ a[1], a[2] });

        priority_queue<arr, vector<arr>, greater<arr>> pq;
        pq.push({ 0, src, k });

        vector<int> dist(n, INT_MAX);

        while (pq.size())
        {
            auto [cost, node, remain_k] = pq.top(); // 언패킹 문법
            pq.pop();

            if (node == dst)
                return cost;

            if (remain_k < 0)
                continue;

            if (dist[node] != INT_MAX && dist[node] > remain_k) // 이거만 추가해야 시간 초과가 안난다.
                continue;

            dist[node] = remain_k;

            for (auto& a : graph[node])
                pq.push({ cost + a.second, a.first, remain_k - 1 });
        }
        return -1;
    }
};
