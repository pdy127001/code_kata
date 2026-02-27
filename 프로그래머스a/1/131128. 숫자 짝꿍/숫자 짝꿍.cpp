#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    sort(X.begin(),X.end(),greater<char>());
    sort(Y.begin(),Y.end());
    for(char c:X){
        while(Y.back()>c){
            Y.pop_back();
        }
        if(Y.back()==c){
            answer.push_back(c);
            Y.pop_back();
        }
    }
    sort(answer.begin(),answer.end(),greater<char>());
    if(answer==""){
        answer.push_back('-');
        answer.push_back('1');
    }
    else if(answer[0]=='0'){
        answer="0";
    }
    return answer;
}