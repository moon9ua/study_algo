#include <bits/stdc++.h>
using namespace std;

int arr[1000004];
// vector<int> arr(1000004); // it에만 알고리즘 쓸 수 있는줄 알았는데...

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n); // ❓ 이렇게도 되네? 왜지? it의 개념을 잘못 알고있었나?
    // sort(arr.begin(), arr.begin() + n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}

// O(nlogn)인 알고리즘으로 풀 수 있다. 병합 정렬, 힙 정렬.
// 내장 알고리즘으로 일단 풀어봤다.