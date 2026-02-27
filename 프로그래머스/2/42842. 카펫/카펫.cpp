#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> divisor;
    int n=0,n1=0,n2=0;
    for(int i=1;i<=yellow;i++){
        if(yellow%i==0){
            divisor.push_back(i);
        }
    }
    n=divisor.size()/2;
    if(n==0){//yellow가 1*1인 케이스
        n=1;
    }
    else if(divisor.size()%2!=0){
        n++;
    }
    for(int i=0;i<n;i++){
        n1=divisor[i]+2;
        n2=yellow/divisor[i]+2;
        if(n1*n2==brown+yellow){
            answer.push_back(n2);
            answer.push_back(n1);
        }
    }
    
    return answer;
}