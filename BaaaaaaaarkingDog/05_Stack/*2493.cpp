#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    stack<int> s;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (s.size() && v[s.top()] >= v[i])
        {

        }
        else
            s.push(i);
    }
}
