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

    cout << q.size() << '\n'; // 💭 아이디어 괜찮았던것 같다... 나같은 일반항 도출 못하는 바보에겐 이게 나은 것 같기도...
    while (!q.empty())
    {
        cout << q.front().first << ' ' << q.front().second << '\n';
        q.pop();
    }
}
