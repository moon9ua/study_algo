#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, a;
    cin >> n >> x;
    while (n--)
    {
        cin >> a; // 이러한 입력이 헷갈린다!
        if (a < x) cout << a << ' ';
    }
}
