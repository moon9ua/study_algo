#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> hash;
    for (auto& a : clothes)
        hash[a[1]]++;

    int ret = 1;
    for (auto& a : hash)
        ret *= (a.second + 1);

    return ret - 1;
}