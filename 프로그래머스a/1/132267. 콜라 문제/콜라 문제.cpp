#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n>=a){
        int get=n/a*b;
        answer+=get;
        n=n%a;
        n+=get;
    }
    return answer;
}