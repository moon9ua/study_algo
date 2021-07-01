#include <bits/stdc++.h>
using namespace std;

int n, r, c;

int func(int n, int r, int c)
{
    if (n == 0)
        return 0;
    int half = pow(2, n - 1); // ❓ 제곱 함수를 몰라서 찾아봄. ❗️ 강의에서는 비트연산자를 사용.
    if (r < half && c < half)
        return func(n - 1, r, c);
    else if (r < half && c >= half)
        return half * half + func(n - 1, r, c - half);
    else if (r >= half && c < half)
        return 2 * half * half + func(n - 1, r - half, c);
    else
        return 3 * half * half + func(n - 1, r - half, c - half);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c;
    cout << func(n, r, c);
}
