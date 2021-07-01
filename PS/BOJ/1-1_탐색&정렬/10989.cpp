#include <bits/stdc++.h>
using namespace std;

int nums[10004];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        int num;
        cin >> num;
        nums[num]++;
    }

    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < nums[i]; j++)
            cout << i << '\n';
    }
}
