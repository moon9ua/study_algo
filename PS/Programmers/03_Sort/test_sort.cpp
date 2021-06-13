#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v({3, 30, 34, 5, 9});

    sort(v.begin(), v.end(), [](int a, int b) -> bool { // [] 생략하면 컴파일 에러.
        // return a < b; // 오름차순 = default = less<int>()
        // return a <= b; // true인 경우에는 등호가 들어가면 안된다고 한다. 정확히는 모르겠지만...
        // return a > b; // 내림차순 = greater<int>()

        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa; // "ab"가 "ba"보다 크면 true
    });

    for (int n : v)
        cout << n << ' ';
}
