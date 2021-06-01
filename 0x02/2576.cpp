#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int min = 101;
    int total = 0;

    for (int i = 0; i < 7; i++) {
        int n;
        cin >> n;
        if (n % 2 == 1) {
            total += n;
            if (n < min) {
                min = n;
            }
        }
    }
    if (min == 101) {
        cout << -1;
    }
    else {
        cout << total << '\n' << min;
    }
}
