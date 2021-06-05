#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int arr['z' - 'a' + 1];

    memset(arr, 0, 26 * sizeof(int)); // sizeof 주의!

    for (char c : str)
    {
        arr[c - 'a'] += 1;
    }

    for (int n : arr)
    {
        cout << n << ' ';
    }
}
