#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string> > clothes)
{

    unordered_map<string, int> hash;

    for (auto cloth : clothes)
        hash[cloth[1]]++;

    int ret = 1;

    for (auto pair : hash)
        // cout << pair.first << ',' << pair.second << '\n';
        ret *= (pair.second + 1);

    return (ret - 1);
}
