#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum=0;
    for(int i=x;i>0;i/=10){
        sum+=i%10;
    }
    if(x%sum!=0){
        answer=false;
    }
    return answer;
}