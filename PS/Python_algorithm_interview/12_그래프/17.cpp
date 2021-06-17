class Solution
{
public:
    const vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno",
                                 "pqrs", "tuv", "wxyz"}; // 아이디어!
    vector<string> ret;

    void dfs(int idx, string path, string digits)
    {
        if (path.size() == digits.size())
        {
            ret.push_back(path);
            return;
        }
        for (int i = idx; i < digits.size(); i++)
            for (auto j : dict[digits[i] - '0'])
                dfs(i + 1, path + j, digits);
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return {};
        dfs(0, "", digits);
        return ret;
    }
};

// 1. 백트래킹 풀이 보고 공부... 꼭 다시 해보자.