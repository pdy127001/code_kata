#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
    unordered_map<int, int> rightCount;
    unordered_set<int> leftSet;

    for (int t : topping) {
        rightCount[t]++;
    }

    int rightKinds = rightCount.size();
    int leftKinds = 0;
    int answer = 0;

    for (int i = 0; i < topping.size() - 1; i++) {
        int cur = topping[i];

        if (leftSet.insert(cur).second) {
            leftKinds++;
        }

        rightCount[cur]--;
        if (rightCount[cur] == 0) {
            rightKinds--;
        }

        if (leftKinds == rightKinds) {
            answer++;
        }
    }

    return answer;
}