#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int toMin(string t){
    return stoi(t.substr(0,2))*60 + stoi(t.substr(3,2));
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int,int>> v;
    
    for(auto &b : book_time){
        int s = toMin(b[0]);
        int e = toMin(b[1]) + 10;
        v.push_back({s,e});
    }
    
    sort(v.begin(), v.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto &t : v){
        if(!pq.empty() && pq.top() <= t.first)
            pq.pop();
        pq.push(t.second);
    }
    
    return pq.size();
}