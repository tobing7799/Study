#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int answer = 0;
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            if (i + j <= k)answer += board[i][j];
        }
    }
    return answer;
}

int main()
{
    cout << solution({ {0, 1, 2} ,{1, 2, 3},{2, 3, 4},{3, 4, 5} }, 2);
}