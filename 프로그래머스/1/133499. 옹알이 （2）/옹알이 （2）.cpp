#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> words = {"aya", "ye", "woo", "ma"};

    for (string s : babbling) {
        string prev = "";
        int i = 0;
        bool ok = true;

        while (i < s.size()) {
            bool matched = false;
            for (string w : words) {
                if (s.substr(i, w.size()) == w && w != prev) {
                    prev = w;       
                    i += w.size();  
                    matched = true;
                    break;
                }
            }
            if (!matched) {
                ok = false;
                break;
            }
        }
        if (ok) answer++;
    }
    return answer;
}