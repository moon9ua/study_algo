#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    list<char> lst; // 이렇게 하는건가? 기억이 안난다.

    for (char c : str)
    {
        lst.push_back(c);
    }

    int n;
    cin >> n;

    list<char>::iterator cursor = lst.end();

    while (n--)
    {
        char c;
        cin >> c;
        if (c == 'L')
        {
            if (cursor != lst.begin())
                cursor--;
        }
        else if (c == 'D')
        {
            if (cursor != lst.end())
                cursor++;
        }
        else if (c == 'B')
        {
            if (cursor != lst.begin())
            {
                list<char>::iterator mover = cursor;
                mover--;
                lst.erase(mover);
            }
        }
        else if (c == 'P')
        {
            char new_c;
            cin >> new_c;
            lst.insert(cursor, new_c);
        }
    }

    for (char c : lst)
    {
        cout << c;
    }
}
