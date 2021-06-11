#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers)
{
    string answer = "";

    sort(numbers.begin(), numbers.end(), [](int a, int b) -> bool
         {
             string s_a = to_string(a);
             string s_b = to_string(b);
             return (s_a + s_b > s_b + s_a); // 📝 이렇게 해줘야함. 혼자는 생각하기 어렵...
         });                                 // 람다 표현식은 잘 썼다! 👍🏻

    for (int n : numbers)
        answer += to_string(n);

    if (answer[0] == '0') // 📝 0만 여러개일 때는 예외처리.
        return "0";

    return answer;
}

// 3과 30의 판별 어떻게? -> 📝 string a,b를 더했을 때 더 큰 기준으로 sort.