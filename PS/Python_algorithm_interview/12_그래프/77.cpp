/*
vector<vector<int> > ret;
int vis[25];

void bt(int len, vector<int> &path, int n, int k, int prev)
{
    if (len == k)
    {
        ret.push_back(path);
        return;
    }

    for (int i = prev + 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            path.push_back(i);
            bt(len + 1, path, n, k, i);
            path.pop_back();
            vis[i] = 0;
        }
    }
}

vector<vector<int> > combine(int n, int k)
{
    vector<int> path;     // path를 레퍼런스로 전달 안하면 10배 이상 느림!
    bt(0, path, n, k, 0); // 레퍼런스로 전달하려면 변수 선언해야.
    return ret;
}
*/

class Solution
{
public:
    vector<vector<int> > ret;
    // int vis[25];

    void dfs(int idx, vector<int> &path, int n, int k, int start)
    {
        if (idx == k)
        {
            ret.push_back(path);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            // if (vis[i] == 0)
            // {
            // vis[i] = 1;
            path.push_back(i);
            dfs(idx + 1, path, n, k, i + 1);
            path.pop_back();
            // vis[i] = 0;
            // }
        }
    }

    vector<vector<int> > combine(int n, int k)
    {
        vector<int> path;
        dfs(0, path, n, k, 1);
        return ret;
    }
};