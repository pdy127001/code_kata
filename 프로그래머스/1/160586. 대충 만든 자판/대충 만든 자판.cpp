#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size(), 0);
    unordered_map<char,int> umap;
    for(int i=0; i<keymap.size(); i++) {
        for(int j=0; j<keymap[i].size(); j++) {
            char c = keymap[i][j];
            if (umap.find(c) != umap.end()) {
                umap[c] = min(umap[c], j+1);
            } else {
                umap[c] = j+1;
            }
        }
    }
    for(int i=0; i<targets.size(); i++) {
        for(int j=0; j<targets[i].size(); j++) {
            char c = targets[i][j];
            if(umap.find(c) != umap.end()) {
                answer[i] += umap[c];
            } else {
                answer[i] = -1;
                break;
            }
        }
    }
    return answer;
}
