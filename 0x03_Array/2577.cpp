#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c; // 개행으로 구분돼도 잘 입력되나?

    int x = a * b * c;
    string str_x = to_string(x);

    int arr[10];
    fill(arr, arr + 10, 0);

    for (char c : str_x)
    {
        arr[c - '0']++;
    }

    for (int n : arr)
    {
        cout << n << '\n';
    }
}
