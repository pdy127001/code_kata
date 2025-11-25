#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> umap;
    for(int i=0;i<clothes.size();i++){
        umap[clothes[i][1]]++;
    }
    for(auto& u : umap){
        answer*=(u.second+1);
    }
    answer--;
    return answer;
}