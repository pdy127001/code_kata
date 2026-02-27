#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int toMinute(const string& time)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    int baseTime = fees[0];
    int baseFee  = fees[1];
    int unitTime = fees[2];
    int unitFee  = fees[3];

    map<string, int> inTime;    
    map<string, int> totalTime;  

    for (const string& r : records)
    {
        string time, car, type;
        stringstream ss(r);
        ss >> time >> car >> type;

        int cur = toMinute(time);

        if (type == "IN")
        {
            inTime[car] = cur;
        }
        else
        {
            totalTime[car] += cur - inTime[car];
            inTime.erase(car);
        }
    }

    int endTime = toMinute("23:59");
    for (auto& p : inTime)
    {
        totalTime[p.first] += endTime - p.second;
    }

    vector<int> answer;
    for (auto& p : totalTime)
    {
        int t = p.second;
        int fee = baseFee;

        if (t > baseTime)
        {
            int extra = t - baseTime;
            fee += ((extra + unitTime - 1) / unitTime) * unitFee;
        }

        answer.push_back(fee);
    }

    return answer;
}