#include <string>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int last_point = 0;

    while (true) {
        bool hasHigher = false;
        for (int i = last_point + 1; i < priorities.size(); i++) {
            if (priorities[i] > priorities[last_point]) {
                hasHigher = true;
                break;
            }
        }

        if (hasHigher) {
            priorities.push_back(priorities[last_point]);
            if (location == last_point) {
                location = priorities.size() - 1;
            }
        }
        else {
            answer++;
            if (location == last_point) {
                return answer;
            }
        }
        last_point++;
    }
}