#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<int> trucks;
    for (int t : truck_weights)
        trucks.push(t);
    queue<pair<int, int> > bridge; // 무게와 들어간 초를 같이 기록
    int sec = 0;
    int w_sum = 0; // 다리 위 트럭 무게

    while (1)
    {
        sec++;
        if (!bridge.empty() && sec - bridge.front().second == bridge_length)
        {
            w_sum -= bridge.front().first;
            bridge.pop();
        }

        if (trucks.empty() && bridge.empty())
            break;

        if (!trucks.empty())
        {
            int truck = trucks.front();
            if (bridge.size() + 1 <= bridge_length && w_sum + truck <= weight)
            {
                bridge.push({truck, sec});
                w_sum += truck;
                trucks.pop();
            }
        }
    }
    return sec;
}

// length를 어떻게 처리?
// sec을 어떻게 처리? 2초 머무르는걸 어떻게? -> 다리 큐에 넣을 때, 초를 같이 입력했다.
// while 문 내의 조건문들의 내용과 순서가 헷갈렸다.
// 📝 w_sum이라는 변수가 있으니, q에는 들어간 초만 기록하면 됐다.
// 📝 trucks와 같은 q는 만들 필요가 없었다. (index로 접근하는 것이 번거로워 만들었지만, 사실 메모리 낭비이긴 하다.)