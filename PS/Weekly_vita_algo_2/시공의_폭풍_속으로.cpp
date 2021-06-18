#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> hash;
    int ret = 0;

    int n = 4;
    while (n--)
    {
        int tmp;
        cin >> tmp;
        hash[tmp]++;
    }

    n = 5;
    while (n--)
    {
        int tmp;
        cin >> tmp;
        if (hash[tmp] == 0)
            ret++;
    }

    cout << ret;
}

// 배열로 하면 되는데 해시로 해버렸네! 아마 배열이 훨씬 빠르겠지...