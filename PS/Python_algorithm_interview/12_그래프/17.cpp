/*
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
*/

class Solution
{
public:
    const vector<string> dict = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ret;

    void dfs(int idx, string path, string digits)
    { // & 쓰면 더 효율적인가? 언제 써야할지 모르겠음.
        if (idx == digits.size())
        {
            ret.push_back(path);
            return;
        }

        for (auto a : dict[digits[idx] - '0'])
        {
            path.push_back(a);
            dfs(idx + 1, path, digits);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return {};
        dfs(0, "", digits);
        return ret;
    }
};