#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ns[100004];
int ms[100004];

void my_bin_search(int target) // 이진 탐색 직접 구현
{
    int left = 0, right = n - 1;
    while (left <= right) // 어떻게? // 탈출 조건이 뭐지?
    {
        int mid = (left + right) / 2;
        if (ns[mid] == target)
        {
            cout << 1 << '\n';
            return;
        }
        else if (target < ns[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << 0 << '\n';
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ns[i];
    sort(ns, ns + n); // nlogn 정렬은 아직 직접 구현해본 적 없다.

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> ms[i];

    for (int i = 0; i < m; i++)
        my_bin_search(ms[i]);
}
