/*
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10]; // 수열 담는 배열
int vis[10]; // 각 숫자 방문했는지.

void bt(int len)
{
    if (len == m)
    {
        for (int i = 0; i < len; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    // for (int i = 0; i < n; i++)
    for (int i = 1; i <= n; i++) // 이게 더 생각 쉬울 듯.
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            // arr[len] = i + 1;
            arr[len] = i;
            bt(len + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    bt(0);
}
// * 백트래킹으로 풀어보기.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 1~n 이 들어있는 배열이나 컨테이너. 어떻게 제일 쉽게 만들지? 반복문 말고는 없나?
    vector<int> v(n);
    for (int i = 1; i <= n; i++)
        v.push_back(i); // 이 방법말고 없나?

    do
    {
        // for (int i = 0; i < m; i++)
        for (int n : v)
            // cout << v[i] << ' ';
            cout << n << ' ';
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));
}
