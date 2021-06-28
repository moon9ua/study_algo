#include <bits/stdc++.h>
using namespace std;

string board[30];
int s;
string n;

const vector<int> dict[10] = {
    {0,1,2,4,5,6}, // 0
    {2,5},
    {0,2,3,4,6},
    {0,2,3,5,6},
    {1,2,3,5},
    {0,1,3,5,6},
    {0,1,3,4,5,6},
    {0,2,5},
    {0,1,2,3,4,5,6},
    {0,1,2,3,5,6} // 9
};

void print_line(int x, int y, bool is_vertical) {
    if (is_vertical) {
        board[y][x] = ' ';
        for (int i = 1; i <= s; i++)
            board[y + i][x] = '|';
        board[y + s + 1][x] = ' ';
    }
    else {
        board[y][x] = ' ';
        for (int i = 1; i <= s; i++)
            board[y][x + i] = '-';
        board[y][x + s + 1] = ' ';
    }
}

void print_num(int num, int idx) {
    vector<int> vec = dict[num];

    int left_x = (s + 3) * idx;
    int right_x = left_x + s + 1;

    for (auto a : vec) {
        if (a == 0)
            print_line(left_x, 0, 0); // 인덱스 너무 헷갈리는데... ㅠㅠ 좋은 방법 맞나?
        else if (a == 1)
            print_line(left_x, 0, 1);
        else if (a == 2)
            print_line(right_x, 0, 1);
        else if (a == 3)
            print_line(left_x, s + 1, 0);
        else if (a == 4)
            print_line(left_x, s + 1, 1);
        else if (a == 5)
            print_line(right_x, s + 1, 1);
        else
            print_line(left_x, 2 * (s + 1), 0);
    }
}

int main() {
    cin >> s >> n;

    // board 초기화 -> ❓ string 배열을 생성자로 초기화하는 법 없나? 있으면 이런 과정 필요 없을텐데...
    for (int i = 0; i < 2 * s + 3; i++)
        board[i] = string(n.size() * (s + 3), ' ');

    // board에 저장
    for (int i = 0; i < n.size(); i++) {
        print_num(n[i] - '0', i);
    }

    // 전체 출력
    for (auto& a : board) {
        if (a == "")
            break;
        cout << a << '\n';
    }
}
