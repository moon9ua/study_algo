#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book)
{
    // for문 2중첩의 방법도 있겠지만... 당연히 효율적인 방법 아닐것.
    // 1. 정렬로 푸는 방법: 정렬해서 인접한 원소만 비교
    // 2. 해시로 푸는 방법
    // 뭐가 더 빠를까?

    unordered_map<string, int> hash;
    for (string phone : phone_book)
        hash[phone]++;

    for (string phone : phone_book)
    {
        string sub = "";
        for (int i = 0; i < phone.size() - 1; i++) // phone.size() 까지 비교하면 자기 자신이 카운트되므로.
        {
            // if (hash[phone.substr(0, i,)]) // substr을 계속 만들면 비효율적일 것.
            sub += phone[i];
            if (hash[sub])
                return false;
        }
    }

    return true;
}
