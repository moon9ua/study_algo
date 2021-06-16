vector<vector<int> > ret;

void bt(vector<int> &cand, int target, vector<int> &path, int idx)
{
    if (target == 0)
    {
        ret.push_back(path);
        return;
    }

    for (int i = idx; i < cand.size(); i++)
    {
        if (target - cand[i] < 0)
            return;
        path.push_back(cand[i]);
        bt(cand, target - cand[i], path, i);
        path.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end()); // 이게 나을까?
    vector<int> path;
    bt(candidates, target, path, 0); // idx 변수를 생각못해 헤맴.
    return ret;
}