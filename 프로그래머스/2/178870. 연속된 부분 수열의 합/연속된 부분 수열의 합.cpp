#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    int left = 0;
    long long sum = 0;
    int bestLen = n + 1;
    vector<int> answer(2, 0);

    for (int right = 0; right < n; ++right) {
        sum += sequence[right];
        while (sum > k && left <= right) {
            sum -= sequence[left++];
        }
        if (sum == k) {
            int len = right - left + 1;
            if (len < bestLen) {
                bestLen = len;
                answer[0] = left;
                answer[1] = right;
            }
        }
    }
    return answer;
}