#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    int man = 1;
    int turn = 1;
    char last = words[0][0];

    unordered_map<string, int> hash;

    for (auto& a : words)
    {
        if (man > n)
        {
            man -= n;
            turn++;
        }

        if (hash[a] > 0 || last != a[0])
            return { man, turn };

        hash[a]++;
        last = a[a.size() - 1];
        man++;
    }

    return { 0,0 };
}