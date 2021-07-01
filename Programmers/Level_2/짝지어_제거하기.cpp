#include <iostream>
#include <string>
using namespace std;
#include <stack>

int solution(string s)
{
    stack<char> st;

    for (auto a : s)
    {
        if (st.size() && a == st.top())
            st.pop();
        else
            st.push(a);
    }

    return (st.empty());
}

// 모두 제거할 수 있으면 1, 아니면 0