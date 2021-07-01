#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, ret = 0;
    cin >> a >> b;

    // int ret = 0;
    for (int i = a; i <= b; i++) {
        ret += i;
        cout << i;
        if (i != b)
            cout << '+';
        else
            cout << '=' << ret;
    }
}
