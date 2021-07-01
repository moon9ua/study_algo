/*
#include <iostream>
using namespace std;

int n, s;
int man[50];
int ret;

void dfs(int idx, int target, int num) {
    if (idx == n)
    {
        if (target == 0 && num)
            ret++;
        return;
    }
    dfs(idx+1, target - man[idx], num+1);
    dfs(idx+1, target, num);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> man[i];

    dfs(0, s, 0);
    cout << ret;
}

// 첫번째 수 (홍현이) 가 무조건 포함되어야 하는걸 못봤음!
*/

#include <iostream>
using namespace std;

int n, s, h;
int man[50];
int ret;

void dfs(int idx, int target) {
    if (idx == n - 1)
    {
        if (target == 0)
            ret++;
        return;
    }
    dfs(idx + 1, target - man[idx]);
    dfs(idx + 1, target);
}

int main() {
    cin >> n >> s >> h;
    for (int i = 0; i < n - 1; i++)
        cin >> man[i];

    dfs(0, s - h);
    cout << ret;
}
