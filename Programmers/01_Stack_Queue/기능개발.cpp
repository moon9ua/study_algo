#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    queue<pair<int, int> > q;
    for (int i = 0; i < speeds.size(); i++)
        q.push({progresses[i], speeds[i]});

    int day = 0, ct = 0;
    while (1)
    {
        if (q.empty())
            break;
        while (!q.empty() && q.front().first + q.front().second * day >= 100)
        {
            q.pop();
            ct++;
        }
        if (ct > 0)
            answer.push_back(ct);
        day++;
        ct = 0;
    }
    return answer;
}