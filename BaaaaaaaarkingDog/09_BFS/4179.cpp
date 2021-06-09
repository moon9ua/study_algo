#include <bits/stdc++.h>
using namespace std;

int r, c;
string board[1002];
int jh[1002][1002];
int fire[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// int ret = INT_MAX; // ❓ INT_MAX. 맞나? // ❗️ 큐는 거리순으로 정렬되므로 최소값을 구할 필요가 없다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    queue<pair<int, int> > fq;
    queue<pair<int, int> > jq;

    for (int i = 0; i < r; i++)
    {
        cin >> board[i];
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == '#') // 💭 벽을 -2로 하는건 어떨까? 생각을 정리하기는 편해진 것 같으나, 코드는 길어진 듯?
            {
                jh[i][j] = -2;
                fire[i][j] = -2;
            }
            else if (board[i][j] == '.')
            {
                jh[i][j] = -1;
                fire[i][j] = -1;
            }
            else if (board[i][j] == 'J')
            {
                jh[i][j] = 0;
                // fire[i][j] = -1; // 💭 넣으나 안넣으나 똑같음. 지훈이 위치는 불이 늦게 도학하기 때문.
                jq.push({i, j});
            }
            else if (board[i][j] == 'F')
            {
                // jh[i][j] = -2; // 💭 넣으나 안넣으나 똑같음. 어짜피 0이 들어가도 큐에 넣지 않게 되므로. 하지만 방문할 수 없으므로 정확히는 -2가 나아보인다.
                fire[i][j] = 0;
                fq.push({i, j});
            }
        }
    }

    while (!fq.empty())
    {
        auto cur = fq.front();
        fq.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (fire[nx][ny] != -1)
                continue;

            fire[nx][ny] = fire[cur.first][cur.second] + 1;
            fq.push({nx, ny});
        }
    }

    while (!jq.empty())
    {
        auto cur = jq.front();
        jq.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            {
                // ret = min(ret, jh[cur.first][cur.second] + 1); // ❗️ 큐는 무조건 거리순으로 쌓이므로, 최초 한번만에 리턴하면 된다.
                cout << jh[cur.first][cur.second] + 1;
                return (0);
            }
            if (jh[nx][ny] != -1)
                continue;

            // jh[nx][ny] = jh[cur.first][cur.second] + 1; // 💭 정확히는 갈 수 없으므로, -1로 두는게 맞긴하다. 결과는 같은듯하지만...
            // if (jh[nx][ny] >= fire[nx][ny])  // ❓ fire[nx][ny] >= 0 조건이 없으면 71%에서 틀린다! 왜?
            if (fire[nx][ny] >= 0 && jh[cur.first][cur.second] + 1 >= fire[nx][ny]) // ❗️ 불이 벽 너머에 있어서 도착 못해 -1일 수도 있기 때문에!!!
                continue;
            jh[nx][ny] = jh[cur.first][cur.second] + 1; // 💭 여기서 갱신해야 깔끔한듯.

            jq.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
}

/*
* ⬜️ 벽을 -2로 해보았는데, -1로 하는게 더 간단할 것 같다. 고치거나 다시 풀어보자.
*/