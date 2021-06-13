#include <bits/stdc++.h>
using namespace std;
#include <map>

int main()
{
    map<string, int> m;

    m["hello"] = 0;
    m["world"] = 1;
    // m.insert({"hello", 0});
    // m.insert({"world", 1});

    // cout << find(m.begin(), m.end(), "hello")->first << '\n'; // 컴파일 에러.
    // cout << find(m.begin(), m.end(), {"hello", 0})->first << '\n'; // 컴파일 에러. pair 객체가 저장되어 있으므로 검색이 안되는걸까?
    cout << m.find("hello")->first << '\n'; // 그래서 연관 컨테이너들은 algorithm의 find 함수가 아닌, 컨테이너 메서드인 find를 사용해야 하는건가?
}
