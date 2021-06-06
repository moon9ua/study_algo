#include <bits/stdc++.h>
using namespace std;

int n;
list<char> lst;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;

        list<char>::iterator cursor = lst.end();
        for (char c : str)
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
                {
                    auto tmp = cursor; // ❓ -가 아닌 --밖에 안돼서... 임시변수 안쓰곤 방법이 없나?
                    tmp--;
                    lst.erase(tmp);
                }
            }
            else
                lst.insert(cursor, c); // 💦 erase와 insert의 위치
        }
        for (char c : lst)
            cout << c;
        cout << '\n';
        lst.clear(); // ❓ 맞나? 다른 더 좋은 방법 있나?
    }
}

/*
* vector와 list 모두 사용해서 시간을 비교해봐야... 리스트가 더 빠른가?
* 스택, 덱으로는 어떻게?
*/