#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    set<int> sums;
    for (int i = 1; i <= elements.size(); i++) {
        for (int start = 0; start < elements.size(); start++) {
            int sum = 0;
            for (int k = 0; k < i; k++) {
                if(start+k>=elements.size()){
                    sum += elements[start+k-elements.size()];
                }
                else{
                    sum += elements[start+k];
                }
            }
            sums.insert(sum);
        }
    }
    return sums.size();
}