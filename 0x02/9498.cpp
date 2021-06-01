#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int score;
    cin >> score;

    if (90 <= score && score <= 100) cout << 'A';
    else if (80 <= score && score <= 89) cout << 'B';
    else if (70 <= score && score <= 79) cout << 'C';
    else if (60 <= score && score <= 69) cout << 'D';
    else cout << 'F';
}
