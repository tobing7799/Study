#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue <int> pq;
    for (int i = 0; i < enemy.size(); ++i, answer++) {
        if (n >= enemy[i]) {
            n -= enemy[i];
            pq.push(enemy[i]);
        }
        else {
            if (!k) break;
            if (!pq.empty() && (pq.top() > enemy[i])) {
                n += pq.top();
                pq.pop();
                n -= enemy[i];
                pq.push(enemy[i]);
            }
            k--;
        }
    }
    return answer;
}

int main()
{
    cout << solution(7, 3, { 4,2,4,5,3,3,1 });
}