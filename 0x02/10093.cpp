#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    if (a > b) {
        swap(a, b);
    } else if (a == b) { // 줄바꿈 안하고 이렇게 하는건가?
        cout << 0;
        return (0);
    } // 테스트 케이스의 중요함...

    int n = b - a - 1;
    cout << n << '\n';

    a += 1;
    while (n--) {
        cout << a << ' ';
        a += 1;
    }
}
