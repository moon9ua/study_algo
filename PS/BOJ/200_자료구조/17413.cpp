#include <bits/stdc++.h>
using namespace std;

int main() {
    string in;
    getline(cin, in); // 이렇게?

    while () {


        if (in == EOF)
            break;
        reverse(in.begin(), in.end());
        cout << in << ' ';
    }
}

// getline을 사용해야 하는 듯. C++의 입력이 항상 헷갈린다.