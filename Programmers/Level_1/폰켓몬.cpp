#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    sort(nums.begin(), nums.end());
    int last = -1;
    for (int n : nums)
    {
        if (last != n)
        {
            last = n;
            answer++;
        }
        if (answer == nums.size() / 2)
            return answer;
    }
    return answer;
}

// 문제: nums에서 절반만 뽑을때, 최대종류수 return.
// 어떻게 풀어야 효율적? 문제 종류는 뭘까?