#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    int total = brown + yellow;
    pair<int, int> ret = {-1, -1};

    for (int i = 1; i <= total / 2; i++)
    {
        if (total % i == 0)
        {
            int x = max(i, total / i);
            int y = min(i, total / i);
            if (ret.first == -1)
                ret = {x, y};
            else if (ret.first - ret.second > x - y && (x - 2) * (y - 2) == yellow) // ❌ 뒤 조건을 빼먹어서 틀렸었음.
                ret = {x, y};
        }
    }

    return vector<int>{ret.first, ret.second};
}

// 테두리 1줄이 갈색
// 중앙이 노란색
// 이렇게 푸는게 맞는걸까?