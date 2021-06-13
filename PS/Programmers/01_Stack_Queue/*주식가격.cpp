#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    // vector<int> ans; // 📝 seg fault!
    vector<int> ans(prices.size());
    stack<int> s;

    for (int i = 0; i < prices.size(); i++)
    {
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            ans[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        ans[s.top()] = prices.size() - s.top() - 1;
        s.pop(); // 📝 이걸 빼먹어서 시간초과가 나기도 했다.
    }
    return ans;
}

// 와 이거 어떻게 풀지? 이게 왜 스택/큐 문제? -> 📝 이중 for문이 아니라, 스택을 이용해서 풀면 O(n)에 풀 수 있기 때문.
// 📝 아무리 동적배열이라고 해도, 할당되지 않은 인덱스에 접근하면 seg fault! vector에 대해 더 공부할 필요가 있겠다.
// 나중에 다시 풀어봐야할 문제. 스택 문제인지 떠올리기도 어렵고, 방법도 내가 직접 생각하기 어려울 듯.