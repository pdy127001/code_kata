#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i=0;i<=t.size()-p.size();i++){
        string str="";
        for(int j=i;j<i+p.size();j++){
            str+=t[j];
        }
        if(stoll(p)>=stoll(str)){
            answer++;
        }
    }
    return answer;
}