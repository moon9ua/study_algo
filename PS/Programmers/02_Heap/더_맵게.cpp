#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    // priority_queue<int> pq(greater<int>(), scoville); // 안된다.
    // priority_queue<int, vector<int>, greater<int> > pq(scoville); // 안된다.
    priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end()); // 이런 식으로만 쓰자.

    // while (pq.size() >= 2)
    while (pq.top() < K) // 이게 더 깔끔.
    {
        if (pq.size() < 2)
            return -1;
        int f1 = pq.top();
        pq.pop();
        int f2 = pq.top();
        pq.pop();
        pq.push(f1 + f2 * 2);
        answer++;
    }
    return answer;
}

// 생성자가 정확히 이해가 안된다. C++의 생성자 정의를 모르겠다. 어떤건 <>에 넣어야하고, 어떤건 ()에 넣기도 하고...
// comp 함수는 <> 안에서만 되나? 레퍼런스 마지막 예제를 보면 () 안에 넣어도 되는 것 같은데...
// 정의에는 다 () 안에 넣는 것처럼 표현해놔서 그걸 모르겠다.