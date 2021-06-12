class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        // 1. 파티션
        auto it_num = stable_partition(logs.begin(), logs.end(),
                                       [](string s) -> bool
                                       {
                                           return (isalpha(s[s.find(' ') + 1]));
                                       });

        // for (string s : logs)
        // cout << s << '\n';

        // 2. 문자 로그 정렬
        sort(logs.begin(), it_num, [](string a, string b) -> bool
             {
                 string sub_a = a.substr(a.find(' ') + 1);
                 string sub_b = b.substr(b.find(' ') + 1);
                 return sub_a == sub_b ? a < b : sub_a < sub_b;
             });

        return logs;
    }
};
