#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
deque<int> d;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) // 원소의 자리
        d.push_back(i);
    while (m--)
    {
        int target;
        cin >> target;

        if (d.front() != target)
        {
            int dis1 = 0;
            int dis2 = 0;

            while (d[dis1] != target)
                // for (auto it = d.begin(); *it != target; it++)
                dis1++;

            // while (d[(n - dis2) % n] != target) // ❌ 일단 여기가 틀렸네. n이 아니다...
            // for (auto it = d.end(); *it != target; --it) // ❌ 조건문에는 --되기 전의 it가 들어가서 틀린듯.
            while (d[(d.size() - dis2) % d.size()] != target) // ❓ 이 부분이 마음에 안든다. 근데 마땅한 방법을 모르겠다...
                dis2++;

            if (dis1 <= dis2)
            {
                while (d.front() != target)
                {
                    d.push_back(d.front());
                    d.pop_front();
                }
                ret += dis1;
            }
            else
            {
                while (d.front() != target)
                {
                    d.push_front(d.back());
                    d.pop_back();
                }
                ret += dis2;
            }
        }
        d.pop_front();
    }
    cout << ret;
}
