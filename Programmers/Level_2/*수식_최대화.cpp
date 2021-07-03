#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long calc(long long a, long long b, char c)
{
    if (c == '*')
        return a * b;
    else if (c == '+')
        return a + b;
    else
        return a - b;
}

long long solution(string expression) {
    vector<char> exp;
    vector<long long> num;
    string str_n;

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '-' || expression[i] == '*' ||
            expression[i] == '+')
        {
            num.push_back(stoll(str_n));
            exp.push_back(expression[i]);
            str_n = "";
        }
        else
            str_n += expression[i];
    }
    num.push_back(stoll(str_n));

    vector<char> v = { '*' ,'+', '-' };
    long long ret = 0;

    do {
        vector<char> exp_tmp = exp;
        vector<long long> num_tmp = num;

        for (char c : v)
        {
            for (int i = 0; i < exp_tmp.size(); i++)
            {
                if (exp_tmp[i] == c)
                {
                    num_tmp[i + 1] = calc(num_tmp[i], num_tmp[i + 1], c);
                    exp_tmp.erase(exp_tmp.begin() + i);
                    num_tmp.erase(num_tmp.begin() + i);
                    i--;
                }
            }
        }
        num_tmp[0] = abs(num_tmp[0]);
        ret = max(ret, num_tmp[0]);
    } while (next_permutation(v.begin(), v.end()));

    return ret;
}
