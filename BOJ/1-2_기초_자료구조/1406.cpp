#include <bits/stdc++.h>
using namespace std;

list<char> lst;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    for (char c : str)
        lst.push_back(c);

    int n;
    cin >> n;

    auto cursor = lst.end();

    while (n--)
    {
        char cmd;
        cin >> cmd;

        if (cmd == 'P')
        {
            char target;
            cin >> target;
            // cursor = lst.insert(cursor, target);
            lst.insert(cursor, target);
        }
        else if (cmd == 'L')
        {
            if (cursor != lst.begin())
                cursor--;
        }
        else if (cmd == 'D')
        {
            if (cursor != lst.end())
                cursor++;
        }
        else
        {
            if (cursor != lst.begin())
            {
                cursor--;
                cursor = lst.erase(cursor);
            }
        }
    }

    for (auto a : lst)
        cout << a;
}
