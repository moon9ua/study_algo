#include <bits/stdc++.h>
using namespace std;

const int mx = 1000005;
int q[mx];
int head = 0, tail = 0;

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

            q[tail++] = x;
        }
        else if (cmd == "pop")
        {
            if (tail - head == 0)
                cout << -1 << '\n';
            else
                cout << q[head++] << '\n';
        }
        else if (cmd == "size")
        {
            cout << tail - head << '\n';
        }
        else if (cmd == "empty")
        {
            if (tail - head == 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (cmd == "front")
        {
            if (tail - head == 0)
                cout << -1 << '\n';
            else
                cout << q[head] << '\n';
        }
        else if (cmd == "back")
        {
            if (tail - head == 0)
                cout << -1 << '\n';
            else
                cout << q[tail - 1] << '\n';
        }
    }
}
