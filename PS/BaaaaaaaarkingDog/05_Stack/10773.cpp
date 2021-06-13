#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    stack<int> st; // st[k] 라고 하나? 초기화 방법을 모르겠음. 생성자 보자.

    while (k--)
    {
        int n;
        cin >> n;

        if (n == 0)
            st.pop();
        else
            st.push(n);
    }

    int ret = 0;

    while (st.empty() == false) // 다른 방법 있나?
    {
        ret += st.top();
        st.pop();
    }

    cout << ret;
}
