#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int s=0;
    for(int i=0;i<section.size();i++){
        if(i==0){
            s=section[i];
            answer++;
        }
        else if(s+m-1<section[i]){
            answer++;
            s=section[i];
        }
    }
    return answer;
}