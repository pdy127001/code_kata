#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int total = 0;
    unordered_map<int,int> umap;
    for(int i=0;i<tangerine.size();i++){
        umap[tangerine[i]]++;
    }
    vector<int> counts;
    for (auto& p : umap){
        counts.push_back(p.second);
    }
    sort(counts.begin(), counts.end(), greater<int>());
    for(int i=0;i<counts.size();i++){
        total+=counts[i];
        if(k<=total){
            answer=i+1;
            break;
        }
    }
    return answer;
}