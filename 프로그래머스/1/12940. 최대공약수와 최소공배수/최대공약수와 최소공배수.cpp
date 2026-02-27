#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer={0,0};
    int max=n;
    int min=m;
    if(max<m){
        max=m;
        min=n;
    }
    for(int i=1;i<=max;i++){
        if(n%i==0&&m%i==0){
            answer[0]=i;
        }
    }
    for(int i=min;i<=min*max;i+=min){
        if(i%m==0&&i%n==0){
            answer[1]=i;
            break;
        }
    }
    return answer;
}