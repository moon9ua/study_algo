#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) // 이거 짧게 쓰는 법 없나?
        q.push(i);

    while (q.size() > 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
}
