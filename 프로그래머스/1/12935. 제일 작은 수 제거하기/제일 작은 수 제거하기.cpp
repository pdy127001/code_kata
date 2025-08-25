#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min=arr[0];
    if(arr.size()==1){
        answer.push_back(-1);
        return answer;
    }
    for(int i=0;i<arr.size();i++){
        if(min>arr[i]){
            min=arr[i];
        }
    }
    arr.erase(remove(arr.begin(), arr.end(), min), arr.end());
    answer=arr;
    return answer;
}