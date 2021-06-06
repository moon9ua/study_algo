#include <bits/stdc++.h>
using namespace std;

int n, k;
bool nums[1000005];
vector<int> arr;
int ret;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        int num;
        cin >> num; // 이렇게 해야하나?

        nums[num] = true;
        arr.push_back(num);
    }

    cin >> k;

    // 시간복잡도
    for (int i = 0; i < arr.size(); i++) // n이 0인 상태라...
        if (1 <= k - arr[i] && k - arr[i] <= 1000000 && nums[k - arr[i]] == true)
            ret++;

    cout << ret / 2; // 이렇게 해도 되나? 더 좋은 아이디어가 있나?
}

/*
* 투포인터로 푼 풀이도 있었다. 시간복잡도의 비교는 못하겠다...
* https://www.acmicpc.net/source/29849041
*/