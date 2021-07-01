#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> st;
int add = 1;
string ret = "";
// stringstream ret;
bool ok = true;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--)
    {
        int target;
        cin >> target;
        if (add <= target)
        {
            st.push(add);
            ret += "+\n";
            if (add == target)
            {
                st.pop();
                ret += "-\n";
            }
            add++;
        }
        else
        {
            cout << "NO\n";
            return (1);
        }
    }
    cout << ret;
}

/*
틀렸음. 나중에 다시!
*/
