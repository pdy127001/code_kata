#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<int> bridge;
    queue<int> trucks;

    for (int w : truck_weights){
        trucks.push(w);        
    }

    for (int i = 0; i < bridge_length; i++){
        bridge.push(0);
    }
    
    int time = 0;
    int currentWeight = 0;

    while (!trucks.empty() || currentWeight > 0)
    {
        time++;
        currentWeight -= bridge.front();
        bridge.pop();

        if (!trucks.empty() && currentWeight + trucks.front() <= weight)
        {
            int truck = trucks.front();
            trucks.pop();
            bridge.push(truck);
            currentWeight += truck;
        }
        else
        {
            bridge.push(0);
        }
    }
    return time;
}