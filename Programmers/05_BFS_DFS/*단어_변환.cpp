#include <string>
#include <vector>

using namespace std;

int vis[54];
int ret;

void dfs(string& cur, int road, string& target, vector<string> words)
{
    if (cur == target)
    {
        ret = min(ret, road);
        return;
    }

    int cnt;
    for (int i = 0; i < words.size(); i++)
    {
        if (vis[i] == 0)
        {
            cnt = 0;
            for (int a = 0; a < cur.size(); a++) // 여기가 생각 안남.
            {
                if (cur[a] != words[i][a])
                    cnt++;
                if (cnt > 1)
                    break;
            }
            if (cnt > 1)
                continue;

            vis[i] = 1;
            dfs(words[i], road + 1, target, words);
            vis[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    ret = 1e9;
    dfs(begin, 0, target, words);
    if (ret == 1e9)
        ret = 0;
    return ret;
}