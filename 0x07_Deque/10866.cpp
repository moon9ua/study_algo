#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> d;

    int n;
    cin >> n;

    while (n--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push_front")
        {
            int x;
            cin >> x;
            d.push_front(x);
        }
        else if (cmd == "push_back")
        {
            int x;
            cin >> x;
            d.push_back(x);
        }
        else if (cmd == "pop_front")
        {
            if (d.empty())
                cout << -1 << '\n';
            else
            {
                cout << d.front() << '\n';
                d.pop_front();
            }
        }
        else if (cmd == "pop_back")
        {
            if (d.empty())
                cout << -1 << '\n';
            else
            {
                cout << d.back() << '\n';
                d.pop_back();
            }
        }
        else if (cmd == "size")
        {
            cout << d.size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << d.empty() << '\n';
        }
        else if (cmd == "front")
        {
            if (d.empty())
                cout << -1 << '\n';
            else
                cout << d.front() << '\n';
        }
        else
        {
            if (d.empty())
                cout << -1 << '\n';
            else
                cout << d.back() << '\n';
        }
    }
}
