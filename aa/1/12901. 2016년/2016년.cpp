#include <string>
#include <vector>

using namespace std;
int month_to_day(int a,int b);
string solution(int a, int b) {
    string answer = "";
    int day;
    day=month_to_day(a,b);
    if(day%7==1){
        answer+="FRI";
    }
    else if(day%7==2){
        answer+="SAT";
    }
    else if(day%7==3){
        answer+="SUN";
    }
    else if(day%7==4){
        answer+="MON";
    }
    else if(day%7==5){
        answer+="TUE";
    }
    else if(day%7==6){
        answer+="WED";
    }
    else if(day%7==0){
        answer+="THU";
    }
    return answer;
}
int month_to_day(int a, int b){
    vector<int> days = {0,31,29,31,30,31,30,31,31,30,31,30,31}; 
    int total = b;
    for (int i = 1; i < a; i++) {
        total += days[i];
    }
    return total;
}
