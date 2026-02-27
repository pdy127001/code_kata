#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<int> v;
    bool BoolSkip;
    int Count=0;
    for(char c : skip){
        v.push_back(c);
    }
    for(char c : s){
        Count=index;
        for(int i=0;i<Count;i++){
            BoolSkip=false;
            c++;
            if(c>'z'){
                c='a';
            }
            for(int j=0;j<v.size();j++){
                if(c==v[j]){
                    BoolSkip=true;
                    break;
                }
            }
            if(BoolSkip){
                Count++;
            }
        }
        answer.push_back(c);
    }
    return answer;
}