#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if (a == b) return a;
    if (a > b) swap(a, b);
    long long sumB = 1LL * b * (b + 1) / 2;
    long long sumA = 1LL * (a - 1) * a / 2;
    answer=sumB-sumA;
    return answer;
}