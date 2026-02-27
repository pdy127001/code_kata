#include <string>
#include <vector>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string token;
    vector<int> v;
    while (getline(ss, token, ' ')) {
        v.push_back(stoi(token));
    }
    int min=v[0],max=v[0];
    for(int i=0;i<v.size();i++){
        if(min>v[i]){
            min=v[i];
        }
        if(max<v[i]){
            max=v[i];
        }
    }
    answer+=to_string(min);
    answer.push_back(' ');
    answer+=to_string(max);
    return answer;
}