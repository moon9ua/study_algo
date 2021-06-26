#include <bits/stdc++.h>
using namespace std;

// 모든 배열은 1~n까지 사용
int top[1004]; // 톱니바퀴의 12시 방향 가리키는 idx
int vis[1004];
int rot[1004]; // 톱니바퀴 회전시킬 방향 (모든 톱니바퀴 순회하면 한번에 돌리기위해)

int main()
{
    int n;
    cin >> n;
    string circles[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> circles[i];

    int k;
    cin >> k;
    while (k--)
    {
        int start_circle, start_dir;
        cin >> start_circle >> start_dir;

        queue<pair<int, int>> q;
        q.push({ start_circle, start_dir });

        while (q.size())
        {
            auto cur = q.front(); q.pop();
            int circle = cur.first;
            int dir = cur.second;

            vis[circle] = 1;
            rot[circle] = dir;

            if (circle + 1 <= n && vis[circle + 1] == 0)
            {
                int cur_top = (top[circle] + 2) % 8;
                int right_top = (top[circle + 1] + 6) % 8;

                if (circles[circle][cur_top] != circles[circle + 1][right_top])
                    q.push({ circle + 1, dir * -1 });
            }
            if (cur.first - 1 >= 1 && vis[cur.first - 1] == 0)
            {
                int cur_top = (top[cur.first] + 6) % 8;
                int left_top = (top[cur.first - 1] + 2) % 8;

                if (circles[circle][cur_top] != circles[circle - 1][left_top])
                    q.push({ circle - 1, dir * -1 });
            }
        }

        for (int i = 1; i <= n; i++) // 한번에 회전시키기
        {
            top[i] += rot[i] * -1;
            if (top[i] < 0)
                top[i] += 8;
            top[i] = top[i] % 8;
        }

        fill(vis + 1, vis + n + 1, 0);
        fill(rot + 1, rot + n + 1, 0);
    }

    int ret = 0;
    for (int i = 1; i <= n; i++)
        if (circles[i][top[i]] == '1')
            ret++;
    cout << ret;
}
