class Solution
{
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs)
    {
        vector<vector<string> > ret;
        unordered_map<string, vector<string> > hash;

        for (string s : strs)
        {
            string tmp = s;
            sort(s.begin(), s.end()); // 원본 바껴서 tmp에 저장하는 수밖에 없나?
            hash[s].push_back(tmp);
        }

        for (auto h : hash)
        {
            ret.push_back(h.second);
        }
        return ret;
    }
};

// 애너그램으로 묶어서 리턴.
// 애너그램 묶은것의 순서는 상관없음.