#include <bits/stdc++.h>
using namespace std;

int arr[104];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
                swap(arr[j], arr[i]);
            else
                break;
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}

// 면접, 손코딩에 많이 나옴.
// 선택정렬? 삽입정렬?