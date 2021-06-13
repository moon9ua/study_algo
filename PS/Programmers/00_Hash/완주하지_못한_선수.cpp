#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    // 이중 반복문으로도 풀 수 있겠지만, 효율적인 방법은 아닐 것.
    // 이름, 개수 테이블을 만들어 비교하면 된다.

    // unordered_map<pair<string, int>> pt; // 이게 아니다!
    unordered_map<string, int> pt;

    for (string str : participant)
    {
        pt[str]++; // 파이썬의 defaultdict처럼 자동으로 추가하나봄.
        // pt.insert({str, 1}); // 이렇게 해야하나?
    }

    for (string str : completion)
    {
        pt[str]--;
    }

    for (auto pair : pt) // pair로 접근하나?
    {
        if (pair.second == 1) // 이렇게?
            return (pair.first);
    }
}
