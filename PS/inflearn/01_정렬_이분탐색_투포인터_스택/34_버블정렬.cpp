#include <bits/stdc++.h>
using namespace std;

int arr[104];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}
