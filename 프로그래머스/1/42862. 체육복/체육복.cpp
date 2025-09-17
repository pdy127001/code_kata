#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int i = 0; i < reserve.size(); i++) {
        for (int j = 0; j < lost.size(); j++) {
            if (reserve[i] == lost[j]) {
                reserve[i] = -1; 
                lost[j] = -1;
                break;
            }
        }
    }

    for (int i = 0; i < reserve.size(); i++) {
        if (reserve[i] == -1) continue; 
        for (int j = 0; j < lost.size(); j++) {
            if (lost[j] == -1) continue; 
            if (reserve[i] - 1 == lost[j] || reserve[i] + 1 == lost[j]) {
                lost[j] = -1; 
                break;     
            }
        }
    }
    int answer = n;
    for (int x : lost) {
        if (x != -1) answer--;
    }
    return answer;
}