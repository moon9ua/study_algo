#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3; i++)
    {
        int n = 0;
        for (int j = 0; j < 4; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                n++;
            }
        }
        if (n == 0) cout << 'D';
        else if (n == 1) cout << 'C';
        else if (n == 2) cout << 'B';
        else if (n == 3) cout << 'A';
        else cout << 'E';
        cout << '\n'; // 이게 없으면 틀린다! 개행에 주의.
    }
}
