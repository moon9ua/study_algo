#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int max = -1;
    int max_i = 0; // 같은 줄에는 못하나?
    for (int i = 0; i < 9; i++) { // K&R 스타일
        int x;
        cin >> x;
        if (x > max) {
            max = x;
            max_i = i;
        }
    }
    cout << max << '\n' << max_i + 1;
}
