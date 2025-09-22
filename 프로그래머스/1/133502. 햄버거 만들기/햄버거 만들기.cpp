#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    vector<int> v;
    int answer = 0;
    for (int x : ingredient) {
        v.push_back(x);
        if (v.size() >= 4) {
            int n = v.size();
            if (v[n-4] == 1 && v[n-3] == 2 &&
                v[n-2] == 3 && v[n-1] == 1) {
                answer++;
                v.pop_back();
                v.pop_back();
                v.pop_back();
                v.pop_back();
            }
        }
    }
    return answer;
}