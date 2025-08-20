#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    if(num==1){
        answer=0;
    }
    else{
        long long n = num;
        for(int i=0;i<500;i++){
            if(n%2==0){
                n/=2;
            }
            else{
                n=n*3+1;
            }
            if(n==1){
                answer=i+1;
                return answer;
            }
        }
        answer=-1;
    }
    
    return answer;
}