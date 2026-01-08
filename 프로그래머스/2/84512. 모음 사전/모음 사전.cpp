#include <string>
#include <vector>

using namespace std;
int solution(string word) {
    int answer = 0;

    int weight[5] = {781, 156, 31, 6, 1};

    for (int i = 0; i < word.length(); i++) {
        int idx = 0;
        switch (word[i]) {
            case 'A': idx = 0; break;
            case 'E': idx = 1; break;
            case 'I': idx = 2; break;
            case 'O': idx = 3; break;
            case 'U': idx = 4; break;
        }
        answer += idx * weight[i];
    }

    answer += word.length();
    return answer;
}