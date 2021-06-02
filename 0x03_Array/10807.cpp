#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[201];
    fill(arr, arr + 201, 0);

    int n;
    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;
        arr[x + 100]++;
    }

    int v;
    cin >> v;

    cout << arr[v + 100];
}
