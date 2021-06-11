#include <string>
#include <vector>

#include <iostream>
#include <unordered_set>
#include <math.h>

using namespace std;

unordered_set<int> ans;
int nums[10];

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    // for (int i = 2; i < n / 2; i++) // ❌ 이렇게 해서 틀렸었음.
    // for (int i = 2; i <= n / 2; i++) // 📝 등호를 포함하면 맞게 된다. 와닿지는 않는게, 예외 케이스를 모르겠다.
    for (int i = 2; i <= sqrt(n); i++) // 📝  제곱근이 일반적으로 더 작으니 효율적이겠지.
        if (n % i == 0)
            return false;
    return true;
}

void rec(string str)
{
    /*
    if (str != "")
    {
        if (ans.find(stoi(str)) != ans.end()) // 존재한다면
            return ;
        else
            ans.insert(stoi(str));
    } // 📝 이렇게 해서 틀렸었음. ⬜️ 왜? 백트래킹에 대한 많은 연습이 필요!
    */

    if (str != "")
        ans.insert(stoi(str));

    for (int i = 0; i < 10; i++) // ⬜️ 큐같은 자료구조로 하면 비효율적 탐색 줄어들까?
    {
        if (nums[i] > 0)
        {
            nums[i]--;
            char c = '0' + i;
            rec(str + string{c});
            // rec(str + string{'0' + i}, num + 1); // 📝 이렇게는 컴파일이 안됨. ⬜️ char->string이 항상 헷갈림.
            nums[i]++;
        }
    }
}

int solution(string numbers)
{
    int ret = 0;

    for (char c : numbers)
        nums[c - '0']++; // 숫자 개수 체크

    rec("");

    for (int n : ans)
    {
        cout << n << ' ';
        if (is_prime(n))
            ret++;
    }

    return (ret);
}

// 소수 확인하는 함수
// 숫자 만드는 함수