/*
// 연결리스트로 시도... 하다 못품
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> ret;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    list<int> lst;
    for (int i = 1; i <= n; i++)
        lst.push_back(i); // 이렇게밖에 못하나?

    auto cur = lst.begin();

    while (!lst.empty())
    {
        for (int i = 0; i < k - 1; i++)
            cur++; // 이런 연산이 되던가?
        ret.push_back(*cur);
        lst.erase(cur);
    }
    for (int i : ret)
        cout << i;
}
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        q.push(i);

    cout << "<";
    while (!q.empty())
    {
        for (int i = 0; i < k - 1; i++)
        {
            q.push(q.front()); // 이거 이렇게 되나? 된다!
            q.pop();
        }
        cout << q.front();
        q.pop();
        if (!q.empty())
            cout << ", ";
    }
    cout << ">";
}
