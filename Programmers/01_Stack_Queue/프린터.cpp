#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    // queue<pair<int, int> > q; // 💡 queue에 index만 삽입하면 더 쉽고 효율적일 것 같다.
    // for (int i = 0; i < priorities.size(); i++)
    // q.push({priorities[i], i});

    deque<pair<int, int> > dq;
    for (int i = 0; i < priorities.size(); i++)
        dq.push_back({priorities[i], i});

    int ret = 1;
    while (!dq.empty())
    {
        while (dq.front().first != max_element(dq.begin(), dq.end())->first)
        {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        if (dq.front().second == location)
            break;
        dq.pop_front();
        ret++;
    }
    return ret;
}
