#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string,int> pos;
    for (int i = 0; i < players.size(); i++) {
        pos[players[i]] = i;
    }

    for (string &name : callings) {
        int idx = pos[name];
        if (idx > 0) {
            string prev = players[idx-1];
            swap(players[idx], players[idx-1]);
            pos[name] = idx-1;
            pos[prev] = idx;
        }
    }
    return players;
}
