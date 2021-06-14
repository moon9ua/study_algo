vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> st;                        // idx
    vector<int> ret(temperatures.size()); // 안하면 컴파일 에러

    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!st.empty() && temperatures[st.top()] < temperatures[i])
        {
            ret[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    // while (!st.empty())
    // {
    //     ret[st.top()] = 0;
    //     st.pop();
    // }

    return ret;
}