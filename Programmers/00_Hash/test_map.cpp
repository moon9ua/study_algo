#include <bits/stdc++.h>
#include <unordered_map> // 따로 해줘야되네? bits로 해결이 안된다.
using namespace std;

int main()
{
    vector<string> strs{"hi", "hello", "world", "moon", "moon", "gua"};
    vector<int> ints{11, 22, 33, 44, 55, 66};

    // unordered_map
    unordered_map<string, int> hash;
    for (int i = 0; i < strs.size(); i++)
        hash.insert({strs[i], ints[i]}); // insert: 이미 있으면 수정x.
    for (auto h : hash)
        cout << "insert: " << h.first << ", " << h.second << '\n'; // 출력해보면 moon이 44.

    unordered_map<string, int> hash2;
    for (int i = 0; i < strs.size(); i++)
        hash2[strs[i]] = ints[i]; // []: 값을 수정하기도 함. 따라서 중복되는 값은 나중 값으로 대체. (multimap류는 불가능)
    for (auto h : hash2)
        cout << "index: " << h.first << ", " << h.second << '\n'; // 출력해보면 moon이 55. 수정됨.

    cout << hash["hi"] << '\n';                // []: (multimap류는 불가능)
    cout << hash.find("moon")->second << '\n'; // find: pair에 대한 포인터를 반환. (iterator라고 하나?)

    cout << hash.count("world") << '\n'; // count: 있으면 1, 없으면 0 (multimap이 아니라 무조건 1)
    cout << hash.count("kk") << '\n';
    cout << hash["kk"] << '\n';       // []: 없는 key에 접근하면 0 출력. key가 생겨버린다!
    cout << hash.count("kk") << '\n'; // 아까는 0이었는데 지금은 key가 생겨서 1을 출력!

    cout << hash.equal_range("world").first->second << '\n'; // equal_range: key를 포함하는 [first, second) pair을 반환. 이 first, second는 각각 또 string, int를 가리키는 pair이다.
    cout << hash.equal_range("world").second->first << '\n'; // unordered라 second는 큰 의미는 없다.

    /*
    // map
    map<string, int> tree;
    // 생성자에서 정렬 기준 정할수 있는걸로 앎. 아직 공부는 안했다.
    for (int i = 0; i < strs.size(); i++)
        tree.insert({strs[i], ints[i]});

    cout << tree.find("hello")->first << '\n';
    cout << next(tree.find("hello"))->first << '\n';
    cout << next(tree.find("hello"), 2)->first << '\n';
    // key를 기준으로 정렬되어 있는 것을 볼 수 있다.

    cout << tree.lower_bound("moon")->first << '\n';
    // equal_range 함수의 begin값과 같다.
    cout << tree.upper_bound("moon")->first << '\n';
    // equal_range 함수의 end값과 같다.
    cout << tree.equal_range("moon").first->first << '\n';
    cout << tree.equal_range("moon").second->first << '\n';
    // 하지만 multi가 아닐때는 의미가 있을까? 언제 사용될까?
    */
}
