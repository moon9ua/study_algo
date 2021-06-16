#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ret;

int solution(int n)
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        int s = 0;
        while (s < n)
        {
            s += j;
            j++;
        }
        if (s == n)
            ret++;
    }
    return ret;
}
