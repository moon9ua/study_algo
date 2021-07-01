// 유니온-파인드

#include <iostream>
using namespace std;

int parent[1000004];

int my_find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = my_find(parent[x]);
}

void my_union(int x, int y)
{
    x = my_find(x);
    y = my_find(y);

    // if (x != y)
    // {
    //     if (x < y)
    //         parent[y] = x; // 이 부분이 헷갈린다. 없애도 통과하긴 한다...
    //     else
    //         parent[x] = y;
    // } // 이런건 언제 필요한거지?

    parent[x] = y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); // 이걸 안해주면 시간초과가 난다!!!

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    int a, b, c;
    while (m--)
    {
        cin >> a >> b >> c;

        if (a == 1)
        {
            if (my_find(b) == my_find(c))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        else
            my_union(b, c);
    }
}
