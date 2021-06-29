#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int mx = 0;
    while (n--) {
        string s;
        cin >> s;
        int sum = 0;
        for (char c : s) {
            sum += c - '0';
        }
        mx = max(mx, sum);
    }
    cout << mx;
}
// 문제는 풀었지만... 문제가 요구하는 방법은 아님
// 그리고 동일한 값일때에 대한 처리 안함!