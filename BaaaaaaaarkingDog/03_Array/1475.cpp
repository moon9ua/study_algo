#include <bits/stdc++.h>
using namespace std;

string n;
int arr[9]; // arr[μ«μ] = κ°μ
int ret;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (char c : n)
    {
        int num = c - '0';
        if (c == '9') // π‘ 9λ 6μΌλ‘ νμΉλ μμ΄λμ΄
            num = 6;
        if (arr[num] == 0)
        {
            for (int i = 0; i < 9; i++)
            {
                arr[i]++;
                if (i == 6) // π‘ μΈνΈλ₯Ό κ΅¬λ§€ν λ 6μ΄ 2κ° μλ€κ³  μκ°
                    arr[i]++;
            }
            ret++;
        }
        arr[num]--;
    }
    cout << ret;
}
