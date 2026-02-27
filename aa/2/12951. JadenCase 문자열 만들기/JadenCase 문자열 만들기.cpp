#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    for(int i=0;i<s.size();i++){
        if(i==0){
            if(s[0]>=97&&s[0]<=122){
                s[0]-=32;
            }
            else{
                continue;
            }
        }
        else if(s[i]==' '){
            if(i+1<s.size()&&s[i+1]!=' '){
                if(s[i+1]>=97&&s[i+1]<=122){
                    s[i+1]-=32;
                }
                i++;
                continue;
            }
        }
        else if(s[i]>=65&&s[i]<=90){
            s[i]+=32;
        }
    }
    answer+=s;
    return answer;
}