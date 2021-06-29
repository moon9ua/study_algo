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

    for (int i = 0; i < n; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[idx] > arr[j])
                idx = j;
        swap(arr[i], arr[idx]);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}

// 선택 정렬