#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int n = arr1.size();           // arr1 행
    int m = arr1[0].size();        // arr1 열 = arr2 행
    int p = arr2[0].size();        // arr2 열

    vector<vector<int>> answer(n, vector<int>(p, 0));

    for (int i = 0; i < n; i++) {        // arr1 행
        for (int j = 0; j < p; j++) {    // arr2 열
            for (int k = 0; k < m; k++) { // arr1의 열 = arr2의 행
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return answer;
}