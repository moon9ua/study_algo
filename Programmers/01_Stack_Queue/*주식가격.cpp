#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    // vector<int> ans; // ๐ seg fault!
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
        s.pop(); // ๐ ์ด๊ฑธ ๋นผ๋จน์ด์ ์๊ฐ์ด๊ณผ๊ฐ ๋๊ธฐ๋ ํ๋ค.
    }
    return ans;
}

// ์ ์ด๊ฑฐ ์ด๋ป๊ฒ ํ์ง? ์ด๊ฒ ์ ์คํ/ํ ๋ฌธ์ ? -> ๐ ์ด์ค for๋ฌธ์ด ์๋๋ผ, ์คํ์ ์ด์ฉํด์ ํ๋ฉด O(n)์ ํ ์ ์๊ธฐ ๋๋ฌธ.
// ๐ ์๋ฌด๋ฆฌ ๋์ ๋ฐฐ์ด์ด๋ผ๊ณ  ํด๋, ํ ๋น๋์ง ์์ ์ธ๋ฑ์ค์ ์ ๊ทผํ๋ฉด seg fault! vector์ ๋ํด ๋ ๊ณต๋ถํ  ํ์๊ฐ ์๊ฒ ๋ค.
// ๋์ค์ ๋ค์ ํ์ด๋ด์ผํ  ๋ฌธ์ . ์คํ ๋ฌธ์ ์ธ์ง ๋ ์ฌ๋ฆฌ๊ธฐ๋ ์ด๋ ต๊ณ , ๋ฐฉ๋ฒ๋ ๋ด๊ฐ ์ง์  ์๊ฐํ๊ธฐ ์ด๋ ค์ธ ๋ฏ.