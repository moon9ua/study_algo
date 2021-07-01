#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string man;
    cin >> man;

    cout << 2019 - (stoi(man.substr(0, 2)) + 1900) + 1 << ' ';
    if (man[man.find('-') + 1] == '1' || man[man.find('-') + 1] == '3')
        cout << 'M';
    else
        cout << 'W';
}

// 3,4 고려안해서 틀림! 수정 귀찮아서...