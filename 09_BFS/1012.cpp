#include <bits/stdc++.h>
using namespace std;

int board[55][55]; // 빈곳은 0, 배추는 1
int vis[55][55];   // 안간곳은 0, 간곳은 1
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > st; // 큐가 너비우선, 스택이 깊이우선?
int ret;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        int m, n, k;
        cin >> m >> n >> k; // 세로가 x축, 가로가 y축.

        while (k--)
        {
            int x, y;
            cin >> x >> y;
            // board[x][y] = 1; // 세로 x축, 가로 y축으로 놨기 때문에, 이렇게 하면 틀린다.
            board[y][x] = 1; // x,y 반전해서 입력해야.
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 1 || board[i][j] == 0) // board 체크를 빼먹었었다.
                    continue;
                vis[i][j] = 1;
                st.push({i, j});

                while (!st.empty())
                {
                    auto cur = st.front();
                    st.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        if (vis[nx][ny] == 1 || board[nx][ny] == 0)
                            continue;

                        vis[nx][ny] = 1;
                        st.push({nx, ny});
                    }
                }
                ret++;
            }
        }
        cout << ret << '\n';
        ret = 0;
        fill(board[0], board[0] + sizeof(board) / sizeof(*board[0]), 0); // 여기를 모르겠다. 2차원 배열의 메모리 초기화.
        fill(vis[0], vis[0] + sizeof(vis) / sizeof(*vis[0]), 0);
        // fill(board[0], board[55], 0); // 이게 되는건가? 모든 칸이 초기화되는게 맞을까? 마지막 칸들은 안된다던지.. 이런건 아닐까..
        // fill(vis[0], vis[55], 0);     // 모든 칸을 쓰지 않으므로 틀리진 않으니 모르겠다.
    }
}

/*
* 기본적인 완전탐색 문제.
* C++17에서는 컴파일 에러이고, C++17(Clang)에서는 통과다. 왜? -> visit 변수명이 문제였다.
*/