#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int Zero_N=0;
    int Answer_N=0;
    for(int i=0;i<lottos.size();i++){
        if(lottos[i]==0){
            Zero_N++;
            continue;
        }
        else{
            auto it =find(win_nums.begin(),win_nums.end(),lottos[i]);
            if(it!=win_nums.end()){
                Answer_N++;
            }
        }
    }
    if(Answer_N+Zero_N==0){
        answer.push_back(6);
    }
    else{
        answer.push_back(7-(Answer_N+Zero_N));
    }
    if(Answer_N==0){
        answer.push_back(6);
    }
    else{
        answer.push_back(7-Answer_N);
    }
    
    return answer;
}