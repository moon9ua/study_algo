class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &nums)
    {
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1, r = nums.size() - 1;

            while (l < r)
            {
                if (l > i + 1 && nums[l] == nums[l - 1])
                {
                    l++;
                    continue;
                }
                if (r < nums.size() - 1 && nums[r] == nums[r + 1])
                {
                    r--;
                    continue;
                }

                int target = 0 - nums[i];
                int now = nums[l] + nums[r];

                if (target == now)
                    ret.push_back({nums[i], nums[l++], nums[r--]});
                else if (target > now)
                    l++;
                else
                    r--;
            }
        }
        return ret;
    }
};

// -4,-1,-1,0,1,2
// 중복제거가 까다롭다.