#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> BFS(int r, int c, vector<vector<int>>& table)
{
    queue<pair<int, int>>q;
    vector<pair<int, int>>result;

    const int dx[] = { 1,0,-1,0 };
    const int dy[] = { 0,1,0,-1 };
    q.push(make_pair(c, r));
    result.push_back(make_pair(c, r));

    table[c][r] = false;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (0 <= nx && nx < table.size() && 0 <= ny && ny < table.size() && table[nx][ny]) {
                result.push_back(make_pair(nx, ny));
                q.push(make_pair(nx, ny));
                table[nx][ny] = false;
            }
        }
    }
    sort(result.begin(), result.end(), [](pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first; });

    return result;
}


int rotate(vector<vector<int>>& matrix, vector<vector<pair<int, int>>>& blocks) {
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));
    vector<vector<pair<int, int>>> boardblocks;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }

    rotated = matrix;

    for (int i = 0; i < rotated.size(); ++i) {
        for (int j = 0; j < rotated.size(); ++j) {
            if (rotated[i][j])
                boardblocks.push_back(BFS(j, i, rotated));
        }
    }

    for (vector<pair<int, int>>& v : blocks) {
        for (vector<pair<int, int>> bblock : boardblocks) {
            if (v.size() != bblock.size()) continue;

            pair<int, int>sub1 = { 100,100 };
            pair<int, int>sub2 = { 100,100 };

            for (pair<int, int> temp : v) {
                if (temp.first < sub1.first) sub1.first = temp.first;
                if (temp.second < sub1.second) sub1.second = temp.second;
            }

            for (pair<int, int> temp : bblock) {
                if (temp.first < sub2.first) sub2.first = temp.first;
                if (temp.second < sub2.second) sub2.second = temp.second;
            }

            for (int i = 0; i < v.size(); ++i) {
                v[i].first -= sub1.first;
                v[i].second -= sub1.second;

                bblock[i].first -= sub2.first;
                bblock[i].second -= sub2.second;
            }

            for (int i = 0; i < v.size(); ++i) {
                if (v[i] != bblock[i]) break;
                else if (i == v.size() - 1) {
                    v.resize(0);
                    for (int k = 0; k < bblock.size(); ++k) {
                        bblock[k].first += sub2.first;
                        bblock[k].second += sub2.second;
                        matrix[bblock[k].first][bblock[k].second] = false;
                        cnt++;
                    }
                }
            }
        }
    }

    return cnt;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;

    vector<vector<pair<int, int>>>blocks;
    vector<vector<pair<int, int>>>boardblocks;


    for (int i = 0; i < game_board.size(); ++i) {
        for (int j = 0; j < game_board.size(); ++j) {
            game_board[i][j] = !game_board[i][j];
        }
    }

    for (int i = 0; i < table.size(); ++i) {
        for (int j = 0; j < table.size(); ++j) {
            if (table[i][j])
                blocks.push_back(BFS(j, i, table));
        }
    }
    

    for (int i = 0; i < 4; ++i) {
		answer += rotate(game_board, blocks);
	}

	return answer;
}

int main()
{
    cout << solution({ {1, 1, 0, 0, 1, 0},{0, 0, 1, 0, 1, 0},{0, 1, 1, 0, 0, 1},{1, 1, 0, 1, 1, 1},{1, 0, 0, 0, 1, 0},{0, 1, 1, 1, 0, 0} }, { {1, 0, 0, 1, 1, 0},{1, 0, 1, 0, 1, 0},{0, 1, 1, 0, 1, 1},{0, 0, 1, 0, 0, 0},{1, 1, 0, 1, 1, 0},{0, 1, 0, 0, 0, 0} });
}

/*
모형 무엇무엇있는지 어떻게 체크? -> 1이나 0 인 부분 bfs 또는 dfs 로 탐색하여 좌표리스트를 묶음으로 따로 만듬
90도 회전 -> 무식하더라도 보드판 자체 행렬을 90도 돌려서 4번체크 하면됨
좌표만 보고 같은 모형인지 어떻게 체크? -> 해당 좌표들을 오름차순으로 정렬하고 시작값을 0,0 을 기준으로 상대좌표로 표시
*/