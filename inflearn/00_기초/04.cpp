#include <bits/stdc++.h>
using namespace std;

int mans[104];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> mans[i];

    sort(mans, mans + n); // 정렬하면 코드가 간단.
    // 정렬 안하고 최소값, 최대값 저장하는게 빠르긴 함.

    cout << mans[n - 1] - mans[0];
}
