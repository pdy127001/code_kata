#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
   
    int n = dungeons.size();
    vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;

    int answer = 0;

    while (next_permutation(order.begin(), order.end())){
        int curK = k;
        int count = 0;

        for (int i = 0; i < n; i++) {
            int idx = order[i];
            int need = dungeons[idx][0];
            int cost = dungeons[idx][1];

            if (curK >= need) {
                curK -= cost;
                count++;
            } else {
                break;
            }
        }

        answer = max(answer, count);

    }

    return answer;
}