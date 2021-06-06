#include <bits/stdc++.h>
using namespace std;

int alpha[30];
string a, b;
int ret;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b; // 띄어쓰기가 없는 문자열이라 이렇게 가능하지만, 공백 있으면 다른 방법 써야할 듯?

    for (char c : a)
        alpha[c - 'a'] += 1;
    for (char c : b)
        alpha[c - 'a'] -= 1;

    for (int n : alpha)
        ret += abs(n);

    cout << ret;
}
