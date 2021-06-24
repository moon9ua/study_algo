#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        int r;
        string s;
        cin >> r >> s;

        for (char c : s)
        {
            for (int i = 0; i < r; i++)
                cout << c;
        }
        cout << '\n';
    }
}
