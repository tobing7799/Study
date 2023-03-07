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
            if (board[i][j] == 0) { // ���� ĭ�� ������ ������ ���
                bool safe = true;
                // ������ 8���� ĭ�� ���ڰ� �ִ��� Ȯ��
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        if (k >= 0 && k < n && l >= 0 && l < n && board[k][l] == 1) {
                            safe = false;
                            break;
                        }
                    }
                    if (!safe) break;
                }
                if (safe) answer++; // ������ ���� ī��Ʈ ����
            }
        }
    }

    return answer;
}
int main()
{
    cout << solution({ {0, 0, 0, 0, 0},{0, 0, 0, 0, 0}, { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0 }});
}