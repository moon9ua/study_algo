#include <bits/stdc++.h>
using namespace std;

const int mx = 1000005;
int q[mx];
int head = 0, tail = 0;

bool empty()
{
    if (tail - head == 0)
        return (true);
    else
        return (false);
}

int size()
{
    return (tail - head);
}

int front()
{
    return (q[head]);
}

int back()
{
    return (q[tail - 1]);
}

void push(int x)
{
    q[tail++] = x;
}

void pop()
{
    if (head < tail)
        head++;
}

int main()
{
    push(11);
    push(22);
    push(33);

    cout << front() << '/' << back() << endl;
    pop();
    cout << front() << '/' << back() << endl;
    pop();
    cout << front() << '/' << back() << endl;
    pop(); // 이렇게 되면 좀 이상한데? STL을 연구 좀 해봐야 할 듯...
    cout << front() << '/' << back() << endl;
}