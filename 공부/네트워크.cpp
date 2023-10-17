#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

int bfs(multimap<int, int>&maps, vector<bool>& visited, int node)
{
    queue<int> q;
    int cnt = 0;

    q.push(node);
    cnt++;
    if (visited[node]) return 0;
    visited[node] = true;

    while (!q.empty()) {
        int nextnode = q.front();
        q.pop();

        for (auto it = maps.lower_bound(nextnode); it != maps.upper_bound(nextnode); ++it) {
            if (visited[it->second]) continue;
            cnt++;
            q.push(it->second);
            visited[it->second] = true;
        }
    }
    return cnt ? 1 : 0;
}



int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    multimap<int, int> maps;
    vector<bool>visited(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < computers[i].size(); ++j) {
            if (i != j && computers[i][j] == 1) {
                maps.insert(make_pair(i, j));
                maps.insert(make_pair(j, i));
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int num = bfs(maps, visited, i);
        if (num) answer++;
    }
    return answer;
}

int main()
{
    cout << solution(3, { {1,1,0}, {1,1,0},{0,0,1} });
}