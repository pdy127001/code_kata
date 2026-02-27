#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> answer;
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && maps[i][j] != 'X') {
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;
                int sum = 0;
                
                while(!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    sum += maps[x][y] - '0';
                    
                    for(int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        
                        if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                            if(!visited[nx][ny] && maps[nx][ny] != 'X') {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                
                answer.push_back(sum);
            }
        }
    }
    
    if(answer.empty()) return {-1};
    
    sort(answer.begin(), answer.end());
    return answer;
}