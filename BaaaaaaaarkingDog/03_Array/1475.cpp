#include <bits/stdc++.h>
using namespace std;

string n;
int arr[9]; // arr[숫자] = 개수
int ret;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (char c : n)
    {
        int num = c - '0';
        if (c == '9') // 💡 9는 6으로 퉁치는 아이디어
            num = 6;
        if (arr[num] == 0)
        {
            for (int i = 0; i < 9; i++)
            {
                arr[i]++;
                if (i == 6) // 💡 세트를 구매할때 6이 2개 있다고 생각
                    arr[i]++;
            }
            ret++;
        }
        arr[num]--;
    }
    cout << ret;
}
