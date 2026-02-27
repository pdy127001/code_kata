#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int n1=0;
    int n2=0;
    char c1;
    for(char c2:s){
        if(n1==0){
            n1++;
            c1=c2;
        }
        else if(c1==c2){
            n1++;
        }
        else{
            n2++;
        }
        if(n1==n2){
            answer++;
            n1=0;
            n2=0;
        }
    }
    if(n1!=n2){
        answer++;
    }
    return answer;
}