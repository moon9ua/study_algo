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