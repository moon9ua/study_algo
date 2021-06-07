#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;

        list<char> lst; // 💭 왜 메모리 누수 발생 안하지?
        auto cursor = lst.end();
        for (char &c : str) // 💭 레퍼런스로 하면 더 효율적?
        {
            if (c == '<')
            {
                if (cursor != lst.begin()) // 💦 &&로 if문 묶어버리면 조건 만족안될때 '<'도 else문으로 들어가버림.
                    cursor--;
            }
            else if (c == '>')
            {
                if (cursor != lst.end())
                    cursor++;
            }
            else if (c == '-')
            {
                if (cursor != lst.begin())
                    lst.erase(prev(cursor));
            }
            else
                lst.insert(cursor, c);
        }
        for (char c : lst)
            cout << c;
        cout << '\n';
        // lst.clear(); // 💭 할 필요 없고 그냥 list 새로 할당하면 될 듯... 왜?
    }
}

/*
* 뭐가 제일 빠를까? vector보다는 list가 빠른건 맞아?
* 스택, 덱으로는 어떻게?
*/