#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int y, m, d;
    char dot;
    stringstream ss(today);
    ss >> y >> dot >> m >> dot >> d;
    int today_days = y * 12 * 28 + m * 28 + d;
    unordered_map<char, int> term_map;
    for (auto& t : terms) {
        stringstream ss_term(t);
        char type;
        int months;
        ss_term >> type >> months;
        term_map[type] = months;
    }
    for (int i = 0; i < privacies.size(); i++) {
        string date_str, term_type;
        stringstream ss_priv(privacies[i]);
        ss_priv >> date_str >> term_type;
        int yy, mm, dd;
        stringstream ss_date(date_str);
        ss_date >> yy >> dot >> mm >> dot >> dd;
        int start_days = yy * 12 * 28 + mm * 28 + dd;
        int expire_days = start_days + term_map[term_type[0]] * 28 - 1;
        if (expire_days < today_days) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}