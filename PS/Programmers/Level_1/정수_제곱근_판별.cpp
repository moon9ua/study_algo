#include <string>
#include <vector>
#include <iostream> //
#include <cmath>    //
#include <typeinfo>

using namespace std;

long long solution(long long n)
{
    long long ll = 1;

    // 시간제한이 없다면...
    while (1)
    {
        if (ll * ll > n)
            break;
        if (ll * ll == n)
            return (ll + 1) * (ll + 1);
        ll++;
    }
    return -1;
}
