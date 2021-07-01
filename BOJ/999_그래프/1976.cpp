/*
3 (도시의 수 n. 1~n)
3 (계획 수 m)
0 1 0 (n개 줄에 n개씩)
1 0 1
0 1 0
1 2 3 (계획)
*/

#include <iostream>
using namespace std;

int parent[204];
int vis[1004];

int my_find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = my_find(parent[x]); // 괄호 없어도 되네.
} // 마지막 재귀 정확히 이해 안됨...

void my_union(int x, int y)
{
    x = my_find(x);
    y = my_find(y);
    parent[y] = x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            if (j < i + 1)
                continue;
            if (tmp == 1)
                my_union(i + 1, j + 1);
        }
    }

    for (int i = 0; i < m; i++)
        cin >> vis[i];

    for (int i = 0; i < m - 1; i++)
    {
        if (my_find(vis[i]) != my_find(vis[i + 1]))
        {
            cout << "NO";
            return (0);
        }
    }
    cout << "YES";
}
