#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

bool compare1(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

bool compare2(pair<int,int>& a, pair<int,int>& b)
{
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> total;
    unordered_map<string, vector<pii>> hash;
    
    for (int i = 0; i < genres.size(); i++)
    {
        total[genres[i]] += plays[i];    
        hash[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<string, int>> tmp(total.begin(), total.end()); // hash 정렬하는 법 (더 좋은 방법 있나?)
    sort(tmp.begin(), tmp.end(), compare1); // 사용자 comp 함수는 항상 헷갈린다.
    
    vector<int> ret;
    for (auto& a : tmp)
    {
        string gen = a.first;
        sort(hash[gen].begin(), hash[gen].end(), compare2);
        ret.push_back(hash[gen][0].second);
        if (hash[gen].size() > 1) // 이거 빼먹었었음.
            ret.push_back(hash[gen][1].second);
    }
    
    return ret;
}
