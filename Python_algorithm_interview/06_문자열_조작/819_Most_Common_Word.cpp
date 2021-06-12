class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_map<string, int> hash;

        int i = 0;
        while (i < paragraph.size())
        {
            string str = "";
            while (paragraph[i] && isalpha(paragraph[i]))
                str += tolower(paragraph[i++]);
            while (paragraph[i] && !isalpha(paragraph[i]))
                i++;
            hash[str]++;
        }

        for (string s : banned)
            hash[s] = 0;

        auto ret = max_element(hash.begin(), hash.end(), [](auto a, auto b) -> bool
                               { return (a.second < b.second); });

        return ret->first;
    }
};