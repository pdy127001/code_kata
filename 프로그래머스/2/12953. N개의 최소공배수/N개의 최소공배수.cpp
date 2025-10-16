#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        int g = gcd(answer, arr[i]); 
        answer = answer * arr[i] / g; 
    }
    return answer;
}