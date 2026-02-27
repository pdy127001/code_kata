#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0;i<numbers.size()-1;i++){
        for(int j=i+1;j<numbers.size();j++){
            int n=numbers[i]+numbers[j];
            auto it=find(answer.begin(),answer.end(),n);
            if(it!=answer.end()){
                continue;
            }
            else{
                answer.push_back(n);
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}