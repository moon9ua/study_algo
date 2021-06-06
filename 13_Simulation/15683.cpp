#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[10][10];
pair<int, int> cctvs[6]; // cctv[번호] = (x,y)
// int ret = INT_MAX;
char capture[10][10];

// 1.4개 2.2개 3.4개 4.4개 5.1개
// for문 5중첩으로 될까?

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void afunc(int i)
{
    pair<int, int> cc = cctvs[1];
    int nx = cc.first;
    int ny = cc.second;

    while (1)
    {
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            return;
        board[nx][ny] = '#';
        nx += dx[i];
        ny += dy[i];
    }
}

void bfunc(int i)
{
    pair<int, int> cc = cctvs[2];
    int nx = cc.first;
    int ny = cc.second;

    while (1)
    {
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            return;
        board[nx][ny] = '#';
        nx += dx[i];
        ny += dy[i];
    }
}

void cfunc()
{
}

void dfunc()
{
}

void efunc()
{
}

void capture_board()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            capture[i][j] = board[i][j];
    // 함수로 하는 방법 없나? 카피?
}

void reload()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            board[i][j] = capture[i][j];
}

void print_board()
{
    cout << "=====" << '\n';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }

    cout << "=====" << '\n';
}

void func()
{
    for (int a = 0; a < 4; a++) // ❓ 중첩 반복문의 시간복잡도는? 4*2*4... 지금은 이런식?
    {
        cout << "=> " << a << '\n';
        capture_board();
        afunc(a);
        for (int b = 0; b < 2; b++)
        {
            capture_board();
            bfunc(b);
            for (int c = 0; c < 4; c++)
            {
                for (int d = 0; d < 4; d++)
                {
                }
            }
            reload();
        }
        reload();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            // board[i][j] += '0'; // cin 문장에서 한번에 못하나?
            if ('1' <= board[i][j] && board[i][j] <= '5')
                // cctvs.push({i, j});
                cctvs[board[i][j] - '0'] = {i, j};
        }

    func();
}

// 백트래킹으로 푸는걸까?