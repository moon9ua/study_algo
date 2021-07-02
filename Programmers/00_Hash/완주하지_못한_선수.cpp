#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> man;

    for (auto& a : completion)
        man[a]++;

    for (auto& a : participant)
    {
        if (man[a] == 0)
            return a;
        man[a]--;
    }
}
