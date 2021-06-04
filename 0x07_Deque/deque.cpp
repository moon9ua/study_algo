const int mx = 1000005;
int d[mx * 2 + 1]; // +1은 왜하는걸까?
int head = mx, tail = mx;

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
    return (d[head]);
}

int back()
{
    return (d[tail - 1]);
}

void push_back(int x)
{
    d[tail++] = x;
}

void push_front(int x)
{
    d[--head] = x;
}

void pop_back()
{
    tail--;
}

void pop_front()
{
    head++;
}

int main()
{
}