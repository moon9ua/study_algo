#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int ret; // ret = 0 으로 초기화해도 소용 없음! main문에서 꼭 다시 초기화 해야...
int vis[8];

int is_meet(vector<char>& road, vector<string>& data)
{
    auto b = road.begin();
    auto e = road.end();
    for (auto& a : data)
    {
        char one = a[0], two = a[2], cmd = a[3];
        int target = a[4] - '0';
        if (cmd == '=')
        {
            if (abs(find(b, e, one) - find(b, e, two)) != target + 1)
                return 0;
        }
        else if (cmd == '>')
        {
            if (abs(find(b, e, one) - find(b, e, two)) <= target + 1)
                return 0;
        }
        else
        {
            if (abs(find(b, e, one) - find(b, e, two)) >= target + 1)
                return 0;
        }
    }
    return 1;
}

void dfs(vector<char>& road, vector<char>& v, vector<string>& data) // 순열부터
{
    if (road.size() == 8)
    {
        ret += is_meet(road, data);
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            road.push_back(v[i]);
            dfs(road, v, data);
            road.pop_back();
            vis[i] = 0;
        }
    }
}

int solution(int n, vector<string> data) {
    ret = 0; // 카카오 문제는 이렇더라... 프로그래머스 문젠가?
    fill(&vis[0], &vis[8], 0);
    
    vector<char> v = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    vector<char> road;
    
    dfs(road, v, data);
    return ret;
}

// 더 좋은 방법 있을까?