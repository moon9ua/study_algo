#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dist(int pos, int target)
{
    int ret = 0;

    if (pos == 0)
        pos = 11;
    if (target == 0)
        target = 11;

    while (pos != target)
    {
        if (pos > target + 1)
            pos -= 3;
        else if (pos < target - 1)
            pos += 3;
        else if (pos < target)
            pos++;
        else if (pos > target)
            pos--;
        ret++;
    }
    return ret;
}

string solution(vector<int> numbers, string hand) {
    string ret;
    bool is_left = (hand == "left");
    int l = 10, r = 12;

    for (int num : numbers)
    {
        if (num == 1 || num == 4 || num == 7)
        {
            l = num;
            ret += 'L';
        }
        else if (num == 3 || num == 6 || num == 9)
        {
            r = num;
            ret += 'R';
        }
        else
        {
            if (dist(l, num) < dist(r, num))
            {
                l = num;
                ret += 'L';
            }
            else if (dist(l, num) > dist(r, num))
            {
                r = num;
                ret += 'R';
            }
            else
            {
                if (is_left)
                {
                    l = num;
                    ret += 'L';
                }
                else
                {
                    r = num;
                    ret += 'R';
                }
            }
        }
    }

    return ret;
}