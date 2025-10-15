#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    a++;
    b++;
    for(;;){
        answer++;
        if(a/2==b/2){
            break;
        }
        else{
            a=a/2+1;
            b=b/2+1;
        }
    }

    return answer;
}