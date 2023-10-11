#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int bfs(int node1, int node2, int vsize, multimap<int, int>&maps)
{
    queue<int> q;
    vector<bool>visited(vsize);
    int cnt = 0;

    q.push(node1);
    visited[node1] = true;
    visited[node2] = true;
    cnt++;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (auto it = maps.lower_bound(node); it != maps.upper_bound(node); ++it) {
            if (visited[it->second]) continue;
            cnt++;
            q.push(it->second);
            visited[it->second] = true;
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    multimap<int, int> maps;

    for (vector<int> v : wires) {
        maps.insert(make_pair(v[0], v[1]));
        maps.insert(make_pair(v[1], v[0]));
    }

    for (vector<int> v : wires) {
        int result = bfs(v[0], v[1], n + 1, maps);
        answer = min(answer, abs(n - result * 2));
    }
    return answer;
}

int main()
{
    cout << solution(9, { {1, 3},{2, 3},{3, 4},{4, 5},{4, 6},{4, 7}, {7, 8}, {7, 9} });
}