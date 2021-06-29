#include <bits/stdc++.h>
using namespace std;

int arr[104];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] >= 0 && arr[j + 1] < 0)
                swap(arr[j], arr[j + 1]);
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}

// 순서는 안변하고, 음의 정수만 앞으로 양의 정수는 뒤로.
// 선택 정렬은 x. 버블 정렬로 o.
// 버블 정렬은 순서가 유지!