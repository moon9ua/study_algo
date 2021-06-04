#include <bits/stdc++.h>
using namespace std;

const int mx = 1000005;
int s[mx];
int top = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push")
        {
            int x;
            cin >> x;

            s[top++] = x;
        }
        else if (cmd == "pop")
        {
            if (top == 0)
                cout << -1 << '\n';
            else
                cout << s[top-- - 1] << '\n';
        }
        else if (cmd == "size")
        {
            cout << top << '\n';
        }
        else if (cmd == "empty")
        {
            if (top == 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (cmd == "top")
        {
            if (top == 0)
                cout << -1 << '\n';
            else
                cout << s[top - 1] << '\n';
        }
    }
}

/*
* stl stack을 가지고 간단하게 풀었어도 된다.
* 함수들을 위에 분리시켜도 됐다.
*/