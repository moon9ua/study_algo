#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        string in;
        cin >> in;

        stack<char> st;
        bool is_break = false;

        for (char c : in) {
            if (c == ')')
            {
                if (st.size() && st.top() == '(')
                    st.pop();
                else {
                    cout << "NO" << '\n';
                    is_break = true;
                    break;
                }
            }
            else
                st.push(c);
        }

        if (is_break)
            continue;

        if (st.size())
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
}
