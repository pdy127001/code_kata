#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    int n=0;
    while(!(s.size()==1&&s[0]=='1')){
        n=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                n++;
            }
            else{
                answer[1]++;
            }
        }
        s="";
        while(n/2!=0){
            s.insert(s.begin(),'0'+n%2);
            n/=2;
        }
        if(n%2!=0){
                    s.insert(s.begin(),'0'+n%2);
        }
        answer[0]++;
    }
    
    return answer;
}