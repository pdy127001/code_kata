#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int n=0;
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[i].size();j++){
            if(park[i][j]=='S'){
                answer.push_back(i);
                answer.push_back(j);
                break;
            }
        }
    }
    for(int i=0;i<routes.size();i++){
        n=0;
        if(routes[i][0]=='E'){
            for(int j=0;j<static_cast<int>(routes[i][2]-'0');j++){
                answer[1]++;
                n--;
                if (answer[1] < 0 || answer[1] >= park[0].size()){
                    answer[1]+=n;
                    j=static_cast<int>(routes[i][2]-'0');
                }
                else if(park[answer[0]][answer[1]]=='X'){
                    answer[1]+=n;
                    j=static_cast<int>(routes[i][2]-'0');
                }
            }
        }
        else if(routes[i][0]=='W'){
            for(int j=0;j<static_cast<int>(routes[i][2]-'0');j++){
                answer[1]--;
                n++;
                if (answer[1] < 0 || answer[1] >= park[0].size()){
                    answer[1]+=n;
                    j=static_cast<int>(routes[i][2]-'0');
                }
                else if(park[answer[0]][answer[1]]=='X'){
                    answer[1]+=n;
                    j=static_cast<int>(routes[i][2]-'0');
                }
            }
        }
        else if(routes[i][0]=='S'){
            for(int j=0;j<static_cast<int>(routes[i][2]-'0');j++){
                answer[0]++;
                n--;
                if (answer[0] < 0 || answer[0] >= park.size()){
                    answer[0]+=n;
                    j=static_cast<int>(routes[i][2]-'0');
                }
                else if(park[answer[0]][answer[1]]=='X'){
                    answer[0]+=n;
                    j=static_cast<int>(routes[i][2]-'0');
                }
            }
        }
        else if(routes[i][0]=='N'){
            for(int j=0;j<static_cast<int>(routes[i][2]-'0');j++){
                answer[0]--;
                n++;
                 if (answer[0] < 0 || answer[0] >= park.size()){
                    answer[0]+=n;
                    j=static_cast<int>(routes[i][2]-'0');
                }
                else if(park[answer[0]][answer[1]]=='X'){
                    answer[0]+=n;
                    j=static_cast<int>(routes[i][2]-'0');
                }
            }
        }
    }
    return answer;
}