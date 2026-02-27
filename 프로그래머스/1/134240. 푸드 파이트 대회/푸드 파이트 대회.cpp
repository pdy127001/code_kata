#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    vector<int> stack;
    for(int i=1;i<food.size();i++){
        for(int j=0;j<food[i]/2;j++){
            answer += to_string(i);
            stack.push_back(i);
        }
    }
    answer += "0";
    for(int i = stack.size()-1; i >= 0; i--) {
    answer += to_string(stack[i]);
    }
    return answer;
}