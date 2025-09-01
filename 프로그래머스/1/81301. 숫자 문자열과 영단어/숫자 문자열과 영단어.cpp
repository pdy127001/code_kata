#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>
using namespace std;

int solution(string s) {
    int answer = 0;
    unordered_map<string,string> umap;
    string buffer="";
    string result = "";
    umap["zero"]="0";
    umap["one"]="1";
    umap["two"]="2";
    umap["three"]="3";
    umap["four"]="4";
    umap["five"]="5";
    umap["six"]="6";
    umap["seven"]="7";
    umap["eight"]="8";
    umap["nine"]="9";
      for (char c : s) {
        if (isdigit(c)) {
            result += c;
        } else {
            buffer += c;
            if (umap.find(buffer) != umap.end()) {
                result += umap[buffer];
                buffer = ""; 
            }
        }
    }
    answer=stoi(result);
    return answer;
}