#include <bits/stdc++.h>
using namespace std;

string str; // 적절한 변수명이 뭘까?
stack<char> s;
int ret;
char prv; // ❌ 이걸 생각 못했음.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    for (char c : str)
    {
        if (c == '(')
            s.push(c);
        else // ')'
        {
            if (prv == '(') // 레이저
            {
                s.pop();
                ret += s.size();
            }
            else // 쇠막대기
            {
                s.pop();
                ret++;
            }
        }
        prv = c;
    }
    cout << ret;
}

/*
* 레이저와 쇠막대기의 구분을 어떻게 할까? -> 바로 앞의 괄호를 저장.
* 잘린 쇠막대기의 수를 어떻게 셀까?
*/