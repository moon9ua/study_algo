#include <bits/stdc++.h>
using namespace std;

string str;
list<char> lst;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    for (char c : str)
        lst.push_back(c);
    list<char>::iterator cursor = lst.end();
    cin >> n;
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
                lst.erase(prev(cursor));
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
