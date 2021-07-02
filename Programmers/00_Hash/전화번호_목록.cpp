/*
// 해시 이용
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book)
{
    unordered_map<string, int> hash;
    for (auto& a : phone_book)
        hash[a]++;

    for (auto& a : phone_book)
    {
        string sub = "";
        for (int i = 0; i < a.size() - 1; i++)
        {
            sub += a[i];
            if (hash[sub])
                return false;
        }
    }
    return true;
}
*/

// 정렬 이용 - 더 효율성 높음
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
            return false;
    }
    return true;
}
