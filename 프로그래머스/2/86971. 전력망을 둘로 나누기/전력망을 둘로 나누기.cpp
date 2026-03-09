#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    for(int i = 0; i < wires.size(); i++){
        vector<vector<int>> adj(n+1);

        for(int j = 0; j < wires.size(); j++){
            if(i == j) continue;
            adj[wires[j][0]].push_back(wires[j][1]);
            adj[wires[j][1]].push_back(wires[j][0]);
        }

        vector<bool> visited(n+1,false);
        queue<int> q;
        q.push(1);
        visited[1] = true;

        int cnt = 1;

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int next : adj[cur]){
                if(!visited[next]){
                    visited[next] = true;
                    q.push(next);
                    cnt++;
                }
            }
        }

        answer = min(answer, abs(cnt - (n-cnt)));
    }

    return answer;
}