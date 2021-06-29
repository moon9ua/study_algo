#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (i % m == 0)
            ret += i;
    }

    cout << ret;
}
