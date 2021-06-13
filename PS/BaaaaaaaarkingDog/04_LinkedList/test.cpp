#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    vector<int> v{4, 5, 6};

    auto it = v.begin();
    auto nx = next(it, 1);

    cout << "nx: " << *nx << '\n';
    cout << "erase it: " << *(v.erase(nx)) << '\n';
    cout << "nx: " << *nx << '\n';

    for (int i : v)
        cout << i << ' ';
}