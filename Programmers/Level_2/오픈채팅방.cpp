// find와 substr 사용 (성능은 더 좋음)
// 20m
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    unordered_map<string, string> hash; // 파싱
    for (auto& a : record)
    {
        string cmd = a.substr(0, a.find(' '));
        if (cmd == "Leave")
            continue;
        
        string id = a.substr(a.find(' ') + 1, a.find_last_of(' ') - 1 - a.find(' '));
        string name = a.substr(a.find_last_of(' ') + 1);
        hash[id] = name;
    }
    
    vector<string> ret;
    for (auto& a : record)
    {
        string cmd = a.substr(0, a.find(' '));
        string id = a.substr(a.find(' ') + 1, a.find_last_of(' ') - 1 - a.find(' '));
        if (cmd == "Enter")
            ret.push_back(string(hash[id]) + "님이 들어왔습니다.");
        else if (cmd == "Leave")
            ret.push_back(string(hash[id]) + "님이 나갔습니다.");
    }
    
    return ret;
}

/*
// stringstream과 getline 사용
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <sstream> // stringstream 아님!

using namespace std;

vector<string> solution(vector<string> record) {
    unordered_map<string, string> hash;
    
    for (auto& a : record)
    {
        istringstream ss(a);
        string cmd, id, name;
        
        getline(ss, cmd, ' ');
        getline(ss, id, ' ');
        getline(ss, name, ' ');
        
        if (cmd == "Leave")
            continue;
            
        hash[id] = name;
    }
    
    vector<string> ret;
    for (auto& a : record)
    {
        istringstream ss(a);
        string cmd, id;
        
        getline(ss, cmd, ' ');
        getline(ss, id, ' ');
        
        if (cmd == "Enter")
            ret.push_back(string(hash[id]) + "님이 들어왔습니다.");
        else if (cmd == "Leave")
            ret.push_back(string(hash[id]) + "님이 나갔습니다.");
    }
    
    return ret;
}
*/