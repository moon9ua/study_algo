#include <bits/stdc++.h>
using namespace std;

int board[505][505];
bool vis[505][505]; // ❗️ 메모리 초기화가 귀찮아서 전역.
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int sz, sz_max, num;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j]; // ❗️ 한줄로 표현 가능
    // ❓ 행,열이 헷갈림. ❗️ 세로가 x, 가로가 y. 즉, arr[x][y].
    // ⬜️ ❓ 세로부터, 혹은 가로부터 순회하는 것이 성능에 차이가 있나? 예를 들어 메모리상에서 멀어진다던지...

    queue<pair<int, int> > q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j] && board[i][j])
            {
                vis[i][j] = 1;
                q.push({i, j}); // ❓ pair을 잘 모르겠다.
                num++;

                while (!q.empty())
                {
                    auto cur = q.front(); // ❗️ auto로 쓰면 된다.
                    q.pop();
                    sz++;

                    for (int i = 0; i < 4; i++)
                    {
                        int nx = cur.first + dx[i]; // ❗️ 작명이 pos_x보다는 nx가 훨씬 간편.
                        int ny = cur.second + dy[i];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        else if (vis[nx][ny] || !board[nx][ny])
                            continue;
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                sz_max = max(sz, sz_max); // ❗️ 한줄로는 이렇게.
                sz = 0;
            }

    cout << num << '\n'
         << sz_max;
}

/*
* ❓ C++17에서는 컴파일 에러가 나고, C++11에서는 된다... 어디가 문제일까?
* ❗️ 변수명을 size라고 했었던 것이 문제!
    * 컴파일 옵션으로 `-std=c++17`을 주면, 미리 컴파일 에러를 찾을 수 있다.
    * 코딩테스트에서도 주로 C++17 버전으로 컴파일하는 듯.
* ❓ 시간복잡도 등에 대해 미리 감이 안잡힘.
*/