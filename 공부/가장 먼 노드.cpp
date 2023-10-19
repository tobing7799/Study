#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

int BFS(int n, multimap<int, int>& m, vector<bool> visited)
{
    queue<pair<int,int>>q;
    map<int, int, greater<>>cnt;
    q.push(make_pair(n, 1));
    visited[n] = true;
    int max = 0;
    bool check = true;
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for (auto it = m.lower_bound(p.first); it != m.upper_bound(p.first); ++it) {
            if (visited[it->second]) continue;
            q.push(make_pair(it->second, p.second+1));
            cnt[p.second + 1]++;
            visited[it->second] = true;
        }
    }
    return cnt.begin()->second;
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    multimap<int, int> m;
    vector<bool>visited(n+1);

    for (vector<int> v : edge) {
        m.insert(make_pair(v[0], v[1]));
        m.insert(make_pair(v[1], v[0]));
    }
    return answer = BFS(1, m, visited);
}

int main()
{
    cout << solution(6, { {3,6},{4,3},{3,2},{1,3},{1,2},{2,4}, {5,2} });
}