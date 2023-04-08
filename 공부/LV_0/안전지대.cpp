#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) { // 현재 칸이 안전한 지역인 경우
                bool safe = true;
                // 인접한 8방향 칸이 지뢰가 있는지 확인
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        if (k >= 0 && k < n && l >= 0 && l < n && board[k][l] == 1) {
                            safe = false;
                            break;
                        }
                    }
                    if (!safe) break;
                }
                if (safe) answer++; // 안전한 지역 카운트 증가
            }
        }
    }

    return answer;
}
int main()
{
    cout << solution({ {0, 0, 0, 0, 0},{0, 0, 0, 0, 0}, { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0 }});
}