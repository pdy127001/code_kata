#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string,int> umap;
    for(int i=0; i<discount.size();i++){
        if(i>9){
            umap[discount[i-10]]--;
        }
        umap[discount[i]]++;
        for(int j=0;j<number.size();j++){
            if(umap[want[j]]!=number[j]){
                break;
            }
            else if(j==number.size()-1){
                answer++;
            }
        }
    }
    return answer;
}