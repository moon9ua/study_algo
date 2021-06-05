#include <bits/stdc++.h>
using namespace std;

const int mx = 1000005; // 왜 이 숫자일까?
int stc[mx];
int idx = 0;

bool empty()
{
    if (idx == 0)
        return (true);
    else
        return (false);
}

int size()
{
    return (idx);
}

int top()
{
    // if (idx > 0)
    return (stc[idx - 1]);
    // else
    // return (0);
}

void push(int x)
{
    stc[idx++] = x;
}

void pop() // void인 것에 주의!
{
    if (idx > 0)
        idx--;
}

int main()
{
    push(1);
    push(2);
    push(3);

    cout << top() << idx << endl;
    pop();
    cout << top() << idx << endl;
    pop();
    cout << top() << idx << endl;
    pop();
    cout << top() << idx << endl;
    pop();
    cout << top() << idx << endl;
}
