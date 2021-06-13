#include <bits/stdc++.h>
using namespace std;

int n, m;
// vector<int> arr;
int arr[11]; // 입력 숫자들
int vis[11]; // 순열 저장?

void func(int len)
{
    if (len == m)
    {
        for (int i = 0; i < len; i++)
            cout << arr[vis[i]] << ' ';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (len && vis[len - 1] >= arr[i])
            continue;
        vis[len] = arr[i];
        func(len + 1);
        vis[len] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    // * 직접 백트래킹으로 구현
    // 백트래킹이란? 재귀랑 무슨 관계?
    func(0);

    // * next_permutation? 함수 사용하는 방법
}

// 모르겠다. 다시 처음부터 풀어보자.