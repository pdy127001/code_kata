#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i=1;i<=number;i++){
        int n=0;
        for(int j=1;j<=i/2;j++){
            if(i%j==0){
                n++;
            }
        }
        n++;
        if(n>limit){
            n=power;
        }
        answer+=n;
    }
    return answer;
}