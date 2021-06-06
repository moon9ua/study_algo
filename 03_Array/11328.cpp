/*
// 첫 풀이
#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;
int al[30];
bool br = false; // ❌ al과 br을 반복문마다 초기화해주지 않아 틀렸었다. 이런건 전역변수로 하지말고 지역변수로 하는게 덜 헷갈릴수도...

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> a >> b;

        if (a.length() != b.length())
        {
            cout << "Impossible" << '\n';
            continue;
        }

        fill(al, al + 30, 0);
        br = false; // ❌ 이 초기화를 빼먹었었다.

        for (char c : a)
            al[c - 'a'] += 1;
        for (char c : b)
        {
            if (al[c - 'a'])
                al[c - 'a'] -= 1;
            else
            {
                br = true; // 💭 더 좋은 방법은 없을까?
                break;
            }
        }
        if (br)
            cout << "Impossible" << '\n';
        else
            cout << "Possible" << '\n';
    }
}
*/

#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;
vector<int> freq1(30); // 💭 알파벳 개수 정확히 모르면 이렇게 쓰는게 빠르지 않을까? 'z'-'a'+1은 너무 기니까...
vector<int> freq2(30); // ❌ () 대신 [] 써서 틀렸었음. 생성자 주의.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> a >> b;

        /*
        vector<int> freq1(30);
        vector<int> freq2(30); // 💭 여기다가 이렇게 쓰면 안될까? 런타임 에러가 발생하는데 왜?
        // ⬜️ ❓ 메모리 해제 이런거 없나? 소멸자는 언제 호출돼? 반복문 넘어가면 원래 있던 freq는 어떻게 되는거야?
        // 애초에 이렇게 하면 런타임에러(double free)가 뜬다.
        */

        for (char c : a)
            freq1[c - 'a'] += 1;
        for (char c : b)
            freq2[c - 'a'] += 1;

        if (freq1 == freq2) // 💭 vector은 이렇게 비교가 가능. 배열은 아마 주소가 비교돼서 안되겠지?
            cout << "Possible" << '\n';
        else
            cout << "Impossible" << '\n';

        fill(freq1.begin(), freq1.end(), 0);
        fill(freq2.begin(), freq2.end(), 0); // 💭 freq2.end() 대신 freq2.begin() + 30 도 가능...
    }
}

/*
* 💡 vector의 ==을 사용하면 원소까지 비교 가능.
* vector 생성자에 유의하자.
* 런타임에러(double free)에 유의하자. (아직도 정확히는 모름)
* fill의 범위는 [start, end).
*/
