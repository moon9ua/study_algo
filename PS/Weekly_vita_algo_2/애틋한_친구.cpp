#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n;
vector<pair<int, int>> man;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        man.push_back({ a,b });
    }

    int mx = 0;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            auto x = man[i], y = man[j];
            auto dist = sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
            if (mx < dist)
            {
                mx = dist;
                a = i, b = j;
            }
        }
    }
    cout << a + 1 << ' ' << b + 1;
}

// O(n^2) 말고는 방법을 모르겠는데..? -> 해설에도 이런 방식으로 나온다.