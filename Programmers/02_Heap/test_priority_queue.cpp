#include <queue>
#include <iostream>

using namespace std;

int main()
{
    // priority_queue<int> pq; // <int, vector<int> > 와 같음.
    // priority_queue<int, deque<int> > pq; // deque로 내부 컨테이너를 변경 가능
    priority_queue<int, vector<int>, greater<int> > pq; // comp 변경 가능: 2번째 인자인 컨테이너를 지정해준 후에 가능. greater<int>()가 아님에 주의!

    pq.push(3);
    pq.push(42);
    pq.push(-1);

    while (!pq.empty())
    {
        cout << pq.top() << '\n';
        pq.pop();
    } // 42, 3, -1. 큰것부터 빠져나옴.
}
