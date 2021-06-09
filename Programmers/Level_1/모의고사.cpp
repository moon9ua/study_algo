#include <string>
#include <vector>

#include <algorithm>

using namespace std;

int ret[3];

vector<int> solution(vector<int> answers)
{
    vector<int> answer;

    /*
    // 첫 풀이. queue를 이용. 다소 복잡.
    queue<int> num1, num2, num3;
    for (int n : {1,2,3,4,5})
        num1.push(n);
    for (int n : {2,1,2,3,2,4,2,5})
        num2.push(n);
    for (int n : {3,3,1,1,2,2,4,4,5,5})
        num3.push(n); // 다른 초기화 방법 없나?
    
    for (int answer : answers)
    {
        if (answer == num1.front())
            ret[0]++;
        if (answer == num2.front())
            ret[1]++;
        if (answer == num3.front())
            ret[2]++;
        num1.push(num1.front()); num1.pop();
        num2.push(num2.front()); num2.pop();
        num3.push(num3.front()); num3.pop();
    }
    */

    vector<int> num1({1, 2, 3, 4, 5}),
        num2({2, 1, 2, 3, 2, 4, 2, 5}),
        num3({3, 3, 1, 1, 2, 2, 4, 4, 5, 5});

    for (int i = 0; i < answers.size(); i++)
    {
        if (num1[i % num1.size()] == answers[i]) // 뭔가 이 부분이 마음에 안든다.
            ret[0]++;
        if (num2[i % num2.size()] == answers[i]) // 10명이라면? 10번을 써야한다.
            ret[1]++;
        if (num3[i % num3.size()] == answers[i]) // 비슷한 내용임에도 불구하고... 다른 방법 없나?
            ret[2]++;
    }

    int max = *max_element(ret, ret + 3);
    for (int i = 0; i < 3; i++)
        if (ret[i] == max)
            answer.push_back(i + 1);

    return answer;
}

// 이런걸 구현 문제라고 하나? 완전탐색이라 아닌가?