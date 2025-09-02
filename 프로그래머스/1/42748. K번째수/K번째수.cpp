#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++){
        vector<int> v1;
        for(int j=commands[i][0]-1;j<commands[i][1];j++){
            v1.push_back(array[j]);
        }
        sort(v1.begin(),v1.end());
        answer.push_back(v1[commands[i][2]-1]);
    }
    return answer;
}