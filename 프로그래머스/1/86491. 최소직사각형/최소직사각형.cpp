#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
     int maxW = 0, maxH = 0;
    for (auto &s : sizes) {
        int a = s[0], b = s[1];
        int big = max(a, b);
        int small = min(a, b);
        maxW = max(maxW, big);
        maxH = max(maxH, small);
    }
    answer=maxW*maxH;
    return answer;
}