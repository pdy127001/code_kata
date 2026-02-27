#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    for(int i=0; i<wallpaper.size();i++){
        for(int j=0; j<wallpaper[i].size();j++){
            if(i==0 and j==0){
                answer.push_back(wallpaper.size());
                answer.push_back(wallpaper[i].size());
                answer.push_back(i);
                answer.push_back(j);
            }   
            if(wallpaper[i][j]=='#'){
                if(answer[0]>i){
                    answer[0]=i;
                }
                if(answer[1]>j){
                    answer[1]=j;
                }
                if(answer[2]<i+1){
                    answer[2]=i+1;
                }
                if(answer[3]<j+1){
                    answer[3]=j+1;
                }
            }
        }
    }
    return answer;
}