#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string def;
    cin >> def;

    while (1)
    {
        string var;
        cin >> var;

        string name;
        stack<string> st;
        char last;

        for (int i = 0; i < var.size(); i++)
        {
            if (i == var.size() - 1)
                last = var[i];
            else if (isalpha(var[i]))
                name += var[i];
            else if (var[i] == '[')
            {
                st.push("[]");
                i++;
            }
            else
                st.push(string{ var[i] }); // 되나?
        }

        string ret(def);
        while (st.size())
        {
            ret += st.top();
            st.pop();
        }

        ret += ' ' + name;
        cout << ret << ";\n";

        if (last == ';')
            break;
    }
}

// C++로 더 쉽게 하는 방법 없을까...?