#include <bits/stdc++.h>
using namespace std;

// int board[105][105]; // ⬜️ ❓ 하나씩 파싱하는 법도 궁금하다. 시도했으나 파싱을 못함.
string board[105]; // ❗️ 띄어쓰기 없으니 board로.
int leng[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        // for (int j = 0; j < m; j++)
        // cin >> board[i][j];
        // ❗ 띄어쓰기가 없어서 이렇게 안된다!
        cin >> board[i];
    }

    fill(leng[0], leng[n], -1); // ❗️ 2차원 배열 메모리 초기화

    queue<pair<int, int> > q;

    leng[0][0] = 0;
    q.push({0, 0});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            // if (leng[nx][ny] != -1 || board[nx][ny] == 0)
            if (leng[nx][ny] != -1 || board[nx][ny] == '0') // 💦 여기를 틀렸었음. string으로 저장했으니 int가 아니다!
                continue;

            leng[nx][ny] = leng[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    cout << leng[n - 1][m - 1] + 1;
}
