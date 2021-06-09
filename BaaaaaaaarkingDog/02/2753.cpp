#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;

    if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
        cout << '1';
    else
        cout << '0';
}
