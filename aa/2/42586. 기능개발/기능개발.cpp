#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int before_complete_time=0;
    int count=1;
    for(int i=0;i<speeds.size();i++){
        int current_complete_time=(100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i]!=0){
            current_complete_time++;
        }
        if(i==0){
            before_complete_time=current_complete_time;
        }
        else if(current_complete_time>before_complete_time){
            answer.push_back(count);
            before_complete_time=current_complete_time;
            count=1;
        }
        else{
            count++;
        }
    }
    answer.push_back(count);
    return answer;
}