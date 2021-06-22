#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    while (a != b)
    {
        if (a % 2 == 0)
            a = a / 2;
        else if (a % 2 == 1)
            a = (a + 1) / 2;

        if (b % 2 == 0)
            b = b / 2;
        else if (b % 2 == 1)
            b = (b + 1) / 2;

        // cout << a << ',' << b << '\n';

        answer++;
    }

    return answer - 1;
}

// n명 토너먼트. 1~n
// 훨씬 간결하게 푼 사람이 많다.