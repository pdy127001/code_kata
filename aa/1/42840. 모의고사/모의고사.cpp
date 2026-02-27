#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> n(3,0);
    vector<int> v1={1,2,3,4,5};
    vector<int> v2={2,1,2,3,2,4,2,5};
    vector<int> v3={3,3,1,1,2,2,4,4,5,5};
    for(int i=0;i<answers.size();i++){
        if (answers[i] == v1[i % v1.size()]) {
            n[0]++;
        }
        if (answers[i] == v2[i % v2.size()]) {
            n[1]++;
        }
        if (answers[i] == v3[i % v3.size()]) {
            n[2]++;
        }
    }
    int mx = *max_element(n.begin(), n.end());
    for (int i=0; i<n.size(); i++) {
        if (n[i] == mx) answer.push_back(i+1);
    }
    sort(answer.begin(),answer.end());
    return answer;
}