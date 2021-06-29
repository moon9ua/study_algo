/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int ret = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0)
                ret++;
        }
        cout << ret << ' ';
    }
} // 시간초과가 염려되는데...
*/


#include <bits/stdc++.h>
using namespace std;
int arr[50005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j = j + i) { // for문을 이렇게도 쓸 수 있음.
            arr[j]++;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';
}
