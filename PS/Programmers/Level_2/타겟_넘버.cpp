#include <string>
#include <vector>

using namespace std;

int ret;

void dfs(int idx, vector<int> &numbers, int target)
{
    if (idx == numbers.size())
    {
        if (target == 0)
            ret++;
        return;
    }
    dfs(idx + 1, numbers, target - numbers[idx]);
    dfs(idx + 1, numbers, target + numbers[idx]);
}

int solution(vector<int> numbers, int target)
{
    dfs(0, numbers, target);
    return ret;
}