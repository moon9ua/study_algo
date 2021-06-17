/*
vector<vector<int> > ret;
int vis[25];

void bt(int len, vector<int> path, vector<int> &nums)
{ // path에 &써도 비슷.
    if (len == nums.size())
    {
        ret.push_back(path);
        return;
    }

    for (auto num : nums)
    {
        int idx = num + 10; // 음수도 범위에 있어서.
        if (vis[idx] == 0)
        {
            vis[idx] = 1;
            path.push_back(num);
            bt(len + 1, path, nums);
            vis[idx] = 0;
            path.pop_back();
        }
    }
}

vector<vector<int> > permute(vector<int> &nums)
{
    bt(0, {}, nums);
    return ret;
}
*/

class Solution
{
public:
    vector<vector<int> > ret;
    int vis[22];

    void dfs(int idx, vector<int> &path, vector<int> &nums)
    {
        if (idx == nums.size())
        {
            ret.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (vis[nums[i] + 10] == 0)
            {
                vis[nums[i] + 10] = 1;
                path.push_back(nums[i]);
                dfs(idx + 1, path, nums);
                path.pop_back();
                vis[nums[i] + 10] = 0;
            }
        }
    }

    vector<vector<int> > permute(vector<int> &nums)
    {
        vector<int> path;
        dfs(0, path, nums);
        return ret;
    }
};