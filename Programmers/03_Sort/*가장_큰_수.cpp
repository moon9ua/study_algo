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
             return (s_a + s_b > s_b + s_a); // π μ΄λ κ² ν΄μ€μΌν¨. νΌμλ μκ°νκΈ° μ΄λ ΅...
         });                                 // λλ€ ννμμ μ μΌλ€! ππ»

    for (int n : numbers)
        answer += to_string(n);

    if (answer[0] == '0') // π 0λ§ μ¬λ¬κ°μΌ λλ μμΈμ²λ¦¬.
        return "0";

    return answer;
}

// 3κ³Ό 30μ νλ³ μ΄λ»κ²? -> π string a,bλ₯Ό λνμ λ λ ν° κΈ°μ€μΌλ‘ sort.