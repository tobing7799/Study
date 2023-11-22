#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y, distance;
    bool leverPulled;
    Point(int _x, int _y, int _distance, bool _leverPulled) : x(_x), y(_y), distance(_distance), leverPulled(_leverPulled) {}
};

int solution(vector<string> maps) {
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    pair<int, int> start, end, lever;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maps[i][j] == 'S') {
                start = make_pair(i, j);
            }
            else if (maps[i][j] == 'E') {
                end = make_pair(i, j);
            }
            else if (maps[i][j] == 'L') {
                lever = make_pair(i, j);
            }
        }
    }

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    queue<Point> q;
    q.push(Point(start.first, start.second, 0, false));
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.x == end.first && curr.y == end.second) {
            return curr.distance;
        }

        if (make_pair(curr.x, curr.y) == lever) {
            curr.leverPulled = true;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && maps[newX][newY] != 'X' && !visited[newX][newY]) {
                q.push(Point(newX, newY, curr.distance + 1, curr.leverPulled));
                visited[newX][newY] = true;
            }
        }
    }

    return -1;
}

int main()
{
    cout << solution({ "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" });
}