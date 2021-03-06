#include <bits/stdc++.h>
using namespace std;

int n;
queue<pair<int, int> > q;

void func(int a, int b, int n)
{
    if (n == 1)
    {
        q.push({a, b});
        return;
    }
    func(a, 6 - a - b, n - 1);
    func(a, b, 1);
    func(6 - a - b, b, n - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(1, 3, n);

    cout << q.size() << '\n'; // đ­ ėė´ëė´ ę´ė°Žėëę˛ ę°ë¤... ëę°ė ėŧë°í­ ëėļ ëĒģíë ë°ëŗ´ėę˛ ė´ę˛ ëė ę˛ ę°ę¸°ë...
    while (!q.empty())
    {
        cout << q.front().first << ' ' << q.front().second << '\n';
        q.pop();
    }
}
