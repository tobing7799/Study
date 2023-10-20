#include <iostream>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;



int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    priority_queue<pair<int, int>> PQ;
    vector<int>dist(N+1);
    vector<vector<pair<int, int>>>vertex(N+1);

    for (vector<int> v : road) {
        vertex[v[0]].push_back(make_pair(v[1], v[2]));
        vertex[v[1]].push_back(make_pair(v[0], v[2]));
    }

    PQ.push(make_pair(0, 1));
    dist.assign(N+1, numeric_limits<int>::max());
    dist[1] = 0;
    
    while (!PQ.empty())
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
        if (Cost >= K) continue;
        for (int i = 0; i < vertex[Cur].size(); i++)
        {
            int Next = vertex[Cur][i].first;
            int nCost = vertex[Cur][i].second;

            if (dist[Next] > Cost + nCost)
            {
                dist[Next] = Cost + nCost;
                PQ.push(make_pair(-dist[Next], Next));
            }
        }
    }

    for (int n : dist) {
        if (n <= K) answer++;
    }

    return answer;
}

int main()
{
    cout << solution(5, { {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} }, 3);
}