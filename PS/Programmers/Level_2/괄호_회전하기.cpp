#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int ret = 0;

    for (int i = 0; i < s.size(); i++)
    {
        stack<char> st;
        bool flag = true;
        for (int j = 0; j < s.size(); j++)
        {
            int idx = i + j < s.size() ? i + j : i + j - s.size();
            if (s[idx] == '[' || s[idx] == '(' || s[idx] == '{')
                st.push(s[idx]);
            else if (
                (s[idx] == ']' && st.top() == '[')
                || (s[idx] == ')' && st.top() == '(')
                || (s[idx] == '}' && st.top() == '{')
                )
                st.pop();
            else
            {
                flag = false;
                break;
            }
        }
        if (st.size())
            flag = false;
        ret += flag;
    }

    return ret;
}