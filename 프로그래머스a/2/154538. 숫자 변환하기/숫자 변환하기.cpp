#include <string>
#include <queue>
#include <vector>
using namespace std;

int solution(int x, int y, int n) {
    vector<bool> visited(y + 1, false);
    queue<pair<int, int>> q;

    q.push({x, 0});
    visited[x] = true;

    while (!q.empty()) {
        auto [cur, cnt] = q.front();
        q.pop();

        if (cur == y){
            return cnt;
        } 

        int nexts[3] = {cur + n, cur * 2, cur * 3};

        for (int next : nexts) {
            if (next <= y && !visited[next]) {
                visited[next] = true;
                q.push({next, cnt + 1});
            }
        }
    }

    return -1;
}