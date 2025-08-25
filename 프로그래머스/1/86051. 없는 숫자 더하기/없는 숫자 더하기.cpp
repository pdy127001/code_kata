#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<int> v1(10, 0);
    for(int i=0;i<numbers.size();i++){
        for(int j=0;j<10;j++){
            if(j==numbers[i]){
                v1[j]=numbers[i];
                break;
            }
        }
    }
    for(int i=0;i<v1.size();i++){
        if(v1[i]==0){
            answer+=i;
        }
    }
    return answer;
}