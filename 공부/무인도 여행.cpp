#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int bfs(int x, int y, int r, int c, vector<vector<int>>& visited, vector<string>& field) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = 1;
    int cost = field[x][y] - '0';

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (0 <= nx && nx < r && 0 <= ny && ny < c && field[nx][ny] != 'X') {
                if (!visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    cost += field[nx][ny] - '0';
                    q.push({ nx, ny });
                }
            }
        }
    }

    return cost;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int r = maps.size();
    int c = maps[0].size();
    vector<vector<int>> visited(r, vector<int>(c, 0));

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (maps[i][j] != 'X' && !visited[i][j]) {
                answer.push_back(bfs(i, j, r, c, visited, maps));
            }
        }
    }

    sort(answer.begin(), answer.end());
    if (answer.empty()) {
        answer.push_back(-1);
    }

    return answer;
}

int main()
{
	for (int n : solution({ "X591X","X1X5X","X231X", "1XXX1" })) {
		cout << n << " ";
	}
}