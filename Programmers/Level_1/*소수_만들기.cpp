#include <vector>
#include <iostream>
using namespace std;

int ret;
vector<int> ns;
vector<int> vis; // 있어야하나?

void recur(int len)
{
    if (len == 3)
    {
        if ()
            ret++;
        return;
    }
}

int solution(vector<int> nums)
{
    ns = nums;
    vis = vector<int>(ns.size());

    recur(0);

    return ret;
}

// 브루트포스? 백트래킹? 이런건 뭐라고 하는거지?
// 반복문을 쓴다면 3중첩이 될 것. 즉 n^3 시간복잡도?
// 재귀로 풀어야겠지. 시간복잡도는 얼마? 로그?
// 아니 소수인것도 재귀로 또 확인해야돼?