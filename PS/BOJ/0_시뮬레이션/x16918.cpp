#include <bits/stdc++.h>
using namespace std;

int r, c, n;
char board[204][204];
int bomb[204][204];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
    cin >> r >> c >> n;

    for (int i = 0; i < r; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < c; j++)
        {
            board[i][j] = str[j];
            if (str[j] == '0')
                bomb[i][j] = 3; // 폭탄은 터질 시간으로 저장.
        }
    }

    if (n >= 2)
    {
        int sec = 1;
        while (1)
        {
            sec++;

            if (sec % 2 == 0)
            {
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        if (board[i][j] == '.')
                        {
                            board[i][j] = '0';
                            bomb[i][j] = sec + 3;
                        }
            }
            else
            {
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        if (bomb[i][j] == sec)
                        {
                            board[i][j] = '.';
                            for (int a = 0; a < 4; a++)
                            {
                                int nx = i + dx[a];
                                int ny = j + dy[a];

                                if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                                    continue;
                                board[nx][ny] = '.'; // 폭탄 없앨 수 있어서 문제.
                            }
                        }
            }

            if (sec == n)
                break;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << board[i][j];
        cout << '\n';
    }
}

/*
#include <bits/stdc++.h>
using namespace std;

int r, c, n;
char board[204][204];
char board2[204][204];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
    cin >> r >> c >> n;
    for (int i = 0; i < r; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < c; j++)
            board[i][j] = str[j];
    }

    if (n >= 2 && n % 2 == 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cout << '0';
            cout << '\n';
        }
        return (0);
    }

    fill(&board2[0][0], &board2[204][203], '0'); // 이게 되나?

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '0') { // BFS로 하면 더 빠르겠지..?
                board2[i][j] = '.';
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                        continue;
                    board2[nx][ny] = '.';
                }
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (n == 0 || n % 4 == 1)
                cout << board[i][j];
            else
                cout << board2[i][j];
        }
        cout << '\n';
    }
}
*/