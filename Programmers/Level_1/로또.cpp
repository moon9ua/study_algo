#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> rk({6, 6, 5, 4, 3, 2, 1});

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    int corr = 0;
    int zr = 0;

    for (int l : lottos)
    {
        if (l == 0)
            zr++;
        else if (find(win_nums.begin(), win_nums.end(), l) != win_nums.end())
            // python의 in과 같이 쓰려면 find 함수밖에 없나?
            corr++;
    }
    answer.push_back(rk[corr + zr]);
    answer.push_back(rk[corr]);
    return answer;
}
