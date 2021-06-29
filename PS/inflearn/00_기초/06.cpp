#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    string str_num;
    for (char c : str) {
        if (isdigit(c))
            str_num += c;
    }

    int num = stoi(str_num);
    int ret = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0)
            ret++;
    }

    cout << num << '\n';
    cout << ret << '\n';
}

// 약수 판별
// isdigit