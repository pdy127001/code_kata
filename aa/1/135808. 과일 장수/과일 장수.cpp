#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(),score.end());
    int n=score.size();
    for(int j=1;j<=n;j++){
        if(j%m==0){
            answer+=score.back()*m;
        }
        score.pop_back();
    }
    return answer;
}