#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<int>& board, int& answer, int col) {
    if (board.size() == col) answer++;
    else {
        for (int i = 0; i < board.size(); ++i) {
            bool flag = true;
            board[col] = i;

            for (int j = 0; j < col; ++j) {
                if (board[col] == board[j] || abs(board[col] - board[j]) == abs(col - j)) {
                    flag = false;
                    break;
                }
            }
            if (flag) dfs(board, answer, col + 1);
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<int> board(n, 0);
    dfs(board, answer, 0);

    return answer;
}

int main()
{
    cout << solution(4);
}