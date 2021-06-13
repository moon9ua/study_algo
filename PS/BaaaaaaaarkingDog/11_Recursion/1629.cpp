#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int func(int a, int b, int c) // 3 5 2 -> 3 2 2 ->
{
    // int ret = 1;
    // while (b--)
    //     ret = ret * a % c;
    // return (ret); // 이렇게 하면 시간초과가 나겠지.

    if (b == 1)
        return (a % c);
    // return func(a, ?, c); // ❓ 여기부터 모르겠었음.
    int ret = func(a, b / 2, c); // ❓ /는 나눗셈이 아니라 몫이었지..?
    ret = ret * ret % c;
    if (b % 2 == 0)
        return ret;
    return ret * a % c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    cout << func(a, b, c);
}
