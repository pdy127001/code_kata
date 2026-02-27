#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> hof;
    for(int i=0;i<score.size();i++){
        if (hof.empty()){
            hof.push_back(score[i]);
        }
        else if(hof.size()<k){
            hof.push_back(score[i]);
            sort(hof.begin(),hof.end(),greater<int>());
        }
        else if(hof.back()<score[i]){
            hof.pop_back();
            hof.push_back(score[i]);
            sort(hof.begin(),hof.end(),greater<int>());
        }
        answer.push_back(hof.back());
    }
    return answer;
}