#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <sstream>
#include <unordered_map>
#include <utility>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    set<pair<string,string>> reportSet;
    for (auto &r : report) {
        stringstream ss(r);
        string from, to;
        ss >> from >> to;
        reportSet.insert({from, to});
    }
    unordered_map<string, int> cnt;
    for (auto &[from, to] : reportSet) {
        cnt[to]++;
    }
    unordered_set<string> banned;
    for (auto &[user, c] : cnt) {
        if (c >= k) banned.insert(user);
    }
    unordered_map<string,int> mail;
    for (auto &[from, to] : reportSet) {
        if (banned.count(to)) {
            mail[from]++;
        }
    }
    vector<int> answer;
    for (auto &id : id_list) {
        answer.push_back(mail[id]); 
    }
    return answer;
}