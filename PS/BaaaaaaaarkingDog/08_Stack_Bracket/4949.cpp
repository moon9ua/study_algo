#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    // while (getline(cin, str)) // ❓ 이렇게 반복문? getline도 잘 모른다.
    while (1) // ❗️ true나 1을 쓰는 것이 더 깔끔.
    {
        getline(cin, str);
        if (str == ".")
            break;

        stack<char> st;
        // int ret = 1; // ❓ 다른 방법은 없나?
        bool ret = true; // ❗️ int 대신 bool이 낫겠다.

        for (char c : str) // ❗️ string 순회 good!
        {
            if (c == '(' || c == '[')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                if (st.empty() || st.top() != '(') // ❗️ 항상 empty를 먼저 확인해야 런타임에러 방지됨.
                {
                    ret = false;
                    break;
                }
                st.pop();
            }
            else if (c == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    ret = false;
                    break;
                }
                st.pop();
            }
        }
        // if (!ret || st.empty() == false)
        if (!st.empty() || !ret) // ❗️ 이렇게 고치는 것이 더 깔끔.
            cout << "no" << '\n';
        else
            cout << "yes" << '\n';
    }
}

/*
* 스택이 비었는지를 확인하지 않아, 처음에 틀렸었다.
* (A | B): A가 true면 B를 확인하지 않는다. 이를 Short-circuit evaluation라고 함.
*/