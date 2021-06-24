#include <bits/stdc++.h>
using namespace std;

int arr[1004];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}

// O(n2)인 알고리즘으로 풀 수 있다. 버블 정렬, 삽입 정렬.
// 버블 정렬로 풀었다.