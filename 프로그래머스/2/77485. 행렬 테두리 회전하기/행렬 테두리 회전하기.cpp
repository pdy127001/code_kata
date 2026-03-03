#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> board(rows, vector<int>(columns));
    int num = 1;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            board[i][j] = num++;

    vector<int> answer;

    for (auto &q : queries) {
        int x1 = q[0] - 1;
        int y1 = q[1] - 1;
        int x2 = q[2] - 1;
        int y2 = q[3] - 1;

        int prev = board[x1][y1];
        int minVal = prev;

        for (int i = x1; i < x2; ++i) {
            board[i][y1] = board[i + 1][y1];
            minVal = min(minVal, board[i][y1]);
        }

        for (int j = y1; j < y2; ++j) {
            board[x2][j] = board[x2][j + 1];
            minVal = min(minVal, board[x2][j]);
        }

        for (int i = x2; i > x1; --i) {
            board[i][y2] = board[i - 1][y2];
            minVal = min(minVal, board[i][y2]);
        }

        for (int j = y2; j > y1 + 0; --j) {
            board[x1][j] = board[x1][j - 1];
            minVal = min(minVal, board[x1][j]);
        }

        board[x1][y1 + 1] = prev;
        answer.push_back(minVal);
    }

    return answer;
}