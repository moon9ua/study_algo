#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string circles[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> circles[i];

    vector<int> vis(n + 1);
    vector<int> top(n + 1);
    vector<int> rot(n + 1);

    int k;
    cin >> k;
    while (k--)
    {
        fill(vis.begin(), vis.end(), 0);
        fill(rot.begin(), rot.end(), 0);

        int start_circle, start_dir;
        cin >> start_circle >> start_dir;

        queue<pair<int, int>> q;
        q.push({ start_circle, start_dir });

        while (q.size())
        {
            auto cur = q.front(); q.pop();
            vis[cur.first] = 1;
            rot[cur.first] = cur.second;

            if (cur.first + 1 <= n && vis[cur.first + 1] == 0)
            {
                int a = (top[cur.first] + 2) % 8;
                int b = (top[cur.first + 1] + 6) % 8;

                if (circles[cur.first][a] != circles[cur.first + 1][b])
                    q.push({ cur.first + 1, cur.second * -1 });
            }
            if (cur.first - 1 >= 1 && vis[cur.first - 1] == 0)
            {
                int a = (top[cur.first] + 6) % 8;
                int b = (top[cur.first - 1] + 2) % 8;

                if (circles[cur.first][a] != circles[cur.first - 1][b])
                    q.push({ cur.first - 1, cur.second * -1 });
            }
        }

        for (int i = 1; i <= n; i++)
        {
            top[i] += rot[i] * -1;
            while (top[i] < 0)
                top[i] += 8;
            top[i] = top[i] % 8;
        }
    }

    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if (circles[i][top[i]] == '1')
            ret++;
    }
    cout << ret;
}
