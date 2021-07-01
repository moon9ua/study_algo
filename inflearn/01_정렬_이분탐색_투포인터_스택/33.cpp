#include <bits/stdc++.h>
using namespace std;

int arr[104];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[idx] < arr[j]) // 내림차순
                idx = j;
        swap(arr[idx], arr[i]);
    } // 선택 정렬

    int rank = 0;
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (prev != arr[i])
            rank++;
        if (rank == 3)
            cout << arr[i];
        prev = arr[i];
    }
}
