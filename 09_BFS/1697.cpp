#include <bits/stdc++.h>
using namespace std;

int sec[100002];
int n, k;
int dx[2] = {-1, 1}; // ❓ 이거 편하게 하는 방법 없나?

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    if (n == k) // ❗️ 이 경우를 생각 못해서 틀렸었다
    {
        cout << 0;
        return (0);
    }

    fill(sec, sec + 100002, -1);

    queue<int> q;
    sec[n] = 0;
    q.push(n);

    while (!q.empty()) // ❗️ sec[k] != -1 로 하면, 위의 예외처리가 필요 없지만... 생각이 날까?
    {
        int cur = q.front();
        q.pop();

        // for (int i = 0; i < 3; i++)
        for (int nx : {cur - 1, cur + 1, cur * 2}) // ❗️ 이렇게 할 수 있다
        {
            // int nx;
            // if (i == 2)
            //     nx = cur * 2;
            // else
            //     nx = cur + dx[i];

            if (nx < 0 || nx > 100000) // ❗️ 운좋게 이 문제는 맞았지만, 이동에는 제약이 없어서 범위를 벗어날 수 있다.
                continue;
            if (sec[nx] != -1)
                continue;
            if (nx == k)
            {
                cout << sec[cur] + 1;
                return (0);
            }

            sec[nx] = sec[cur] + 1;
            q.push(nx);
        }
    }
}
