#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> ternary;
    while(n > 0){
        ternary.push_back(n % 3);
        n /= 3;
    }
    for(int i = 0; i < ternary.size(); i++){
        answer = answer * 3 + ternary[i];
    }
    return answer;
}