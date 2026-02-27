#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0, sum2 = 0;
    for (int x : queue1) sum1 += x;
    for (int x : queue2) sum2 += x;

    long long total = sum1 + sum2;
    if (total % 2 != 0) return -1;

    long long target = total / 2;

    int n = queue1.size();
    vector<int> q;
    q.reserve(2 * n);
    for (int x : queue1) q.push_back(x);
    for (int x : queue2) q.push_back(x);

    int left = 0, right = n;
    int answer = 0;
    int limit = 4 * n;

    while (answer <= limit) {
        if (sum1 == target) return answer;
        if (sum1 < target) {
            if (right >= 2 * n) return -1;
            sum1 += q[right++];
        } else {
            sum1 -= q[left++];
        }
        answer++;
    }

    return -1;
}