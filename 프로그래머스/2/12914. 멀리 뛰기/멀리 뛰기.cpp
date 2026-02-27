#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long n1=1,n2=2;
    if(n==1){
        answer=n1;
        return answer;
    }
    else if(n==2){
        answer=n2;
        return answer;
    }
    for(int i=3;i<=n;i++){
        answer=(n1+n2)%1234567;
        n1=n2;
        n2=answer;
    }
    return answer;
}