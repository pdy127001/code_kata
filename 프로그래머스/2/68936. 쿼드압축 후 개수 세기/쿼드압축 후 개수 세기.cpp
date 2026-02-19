#include <vector>
using namespace std;

void compress(vector<vector<int>>& arr, int x, int y, int size, int& zero, int& one) {
    int first = arr[x][y];
    bool same = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != first) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        if (first == 0) zero++;
        else one++;
        return;
    }

    int half = size / 2;
    compress(arr, x, y, half, zero, one);
    compress(arr, x, y + half, half, zero, one);
    compress(arr, x + half, y, half, zero, one);
    compress(arr, x + half, y + half, half, zero, one);
}

vector<int> solution(vector<vector<int>> arr) {
    int zero = 0, one = 0;
    compress(arr, 0, 0, arr.size(), zero, one);
    return {zero, one};
}
