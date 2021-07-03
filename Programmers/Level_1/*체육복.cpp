#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < reserve.size(); i++)
    {
        if (binary_search(lost.begin(), lost.end(), reserve[i]))
        {
            lost.erase(lower_bound(lost.begin(), lost.end(), reserve[i])); // upper_bound와 헷갈렸음.
            reserve.erase(reserve.begin() + i);
            i--;
        }
    }

    int i = 0; // reserve
    int j = 0; // lost
    while (!lost.empty() && !reserve.empty() &&
        i < reserve.size() && j < lost.size())
    {
        // if (binary_search(lost.begin(), lost.end(), reserve[i])) // 왜 여기에 하면 안될까?
        // {
        //     lost.erase(lower_bound(lost.begin(), lost.end(), reserve[i]));
        //     reserve.erase(reserve.begin() + i);
        //     continue;
        // }

        if (lost[j] - 1 > reserve[i])
            i++;
        else if (lost[j] + 1 < reserve[i])
            j++;
        else
        {
            lost.erase(lost.begin() + j);
            reserve.erase(reserve.begin() + i);
        }
    }
    return n - lost.size();
}

// 5, [2, 3, 4], [3, 4, 5]
// 이 경우를 생각 못했었음.