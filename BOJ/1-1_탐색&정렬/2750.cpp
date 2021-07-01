// O(n^2) 정렬 방법
// 1. 선택 정렬
// 2. 삽입 정렬
// 3. 버블 정렬

/*
// 0. stl sort
#include <bits/stdc++.h>
using namespace std;

int arr[1004];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}
*/

/*
// 1. 버블 정렬
#include <bits/stdc++.h>
using namespace std;

int arr[1004];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}
*/

/*
// 2. 선택 정렬
#include <bits/stdc++.h>
using namespace std;

int arr[1004];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 1; i < n; i++)
    {
        int idx = i - 1;
        for (int j = i; j < n; j++)
        {
            if (arr[idx] > arr[j])
                idx = j;
        }
        swap(arr[idx], arr[i - 1]);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}
*/

// 3. 삽입 정렬
#include <bits/stdc++.h>
using namespace std;

int arr[1004];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 1; i < n; i++)
    {
        int tmp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > tmp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}