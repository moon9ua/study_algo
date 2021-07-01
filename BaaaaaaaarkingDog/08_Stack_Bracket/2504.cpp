#include <bits/stdc++.h>
using namespace std;

stack<int> st;
// char pv;
// int ret;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    // if (str[0] == ')' || str[0] == ']')
    // {
    //     cout << 0 << '\n';
    //     return (1);
    // }

    for (char c : str)
    {
        cout << "c:" << c << '\n';
        int tmp;
        if (c == '(' || c == '[')
            st.push(c * -1);
        else if (c == ')')
        {
            if (st.top() > 0)
            {
                tmp = st.top();
                st.pop();
                if (st.top() != '(' * -1)
                {
                    cout << 4242 << '\n';
                    return (1);
                }
                st.pop();
                st.push(tmp * 2);
            }
            else if (st.top() == '(' * -1)
            {
                st.pop();
                st.push(2);
            }
        }
        else if (c == ']')
        {
            if (st.top() > 0)
            {
                tmp = st.top();
                st.pop();
                if (st.top() != '[' * -1)
                {
                    cout << 42 << '\n';
                    return (1);
                }
                st.pop();
                st.push(tmp * 3);
            }
            else if (st.top() == '[' * -1)
            {
                st.pop();
                st.push(3);
            }
        }
    }

    int ret = 0;
    while (!st.empty())
    {
        ret += st.top();
        st.pop();
    }
    cout << ret << '\n';
}

/*
* 수인지, 곱인지 판별 -> 앞의 값으로
* 덧셈은 어떻게? -> 💡 값도 스택에 넣는다는 아이디어 (나는 생각 못함)
*/

// 으악 졸리다... 내일 하자.