#include <bits/stdc++.h>
using namespace std;

// int board[70][70];
string board[70];

void func(int x, int y, int n)
{
    char color = board[x][y];
    bool end = true;

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (board[i][j] != color)
            {
                end = false;
                break;
            }
        }
        if (end == false)
            break;
    }

    if (end)
    {
        cout << color; // 출력하는거랑 값 스트링에 저장하는거랑 차이 없을듯. 2차원도 아니고...
        return;
    }

    cout << '(';
    func(x, y, n / 2);
    func(x, y + n / 2, n / 2); // 💡 xy 좌표 뒤집혀서 y 먼저... 이게 항상 헷갈림. 정립이 안돼서 생각을 거쳐야함.
    func(x + n / 2, y, n / 2);
    func(x + n / 2, y + n / 2, n / 2);
    cout << ')';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];

    func(0, 0, n);
}

/*
* 나중에 다시 풀어볼 것!
*/