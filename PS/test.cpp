#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr)
{
    unordered_map<int, int> hash;

    for (int n : arr)
        hash[n]++;

    vector<int> ret;

    for (int n : arr)
    {
        if (hash[n] == 0 || hash[n] == 1)
            continue;
        ret.push_back(hash[n]);
        hash[n] = 0;
    }

    if (ret.empty())
        return {-1};

    return ret;
}

// 해시테이블을 만든다?

int main()
{
    vector<int> test = {3, 5, 7};

    auto ret = solution(test);

    for (auto a : ret)
        cout << a << ' ';
}