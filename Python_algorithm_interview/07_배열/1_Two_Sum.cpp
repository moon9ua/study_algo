/*
// 1
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            auto target_it = find(nums.begin(), nums.end(), target - nums[i]);
            if (target_it != nums.end())
            {
                int idx = target_it - nums.begin();
                if (i != idx)
                    return (vector<int>({i, idx}));
            }
        }
        return vector<int>();
    }
};
*/

// 2
/*
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++)
            hash[nums[i]] = i; // idx 저장

        for (int i = 0; i < nums.size(); i++)
        {
            // 있는지 확인하려면 find 쓰면 되나?
            auto find_it = hash.find(target - nums[i]);
            if (find_it != hash.end() && i != find_it->second)
                return vector<int>({i, find_it->second});
        }
        return vector<int>();
    }
};
*/

// 3
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = hash.find(target - nums[i]);
            if (it != hash.end()) // 테이블에 상대가 있다면? 리턴
                return vector<int>({it->second, i});
            hash[nums[i]] = i;
        }
        return vector<int>{};
    }
};