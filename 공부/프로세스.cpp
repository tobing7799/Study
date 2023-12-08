#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>>q;
    for (int i = 0; i < priorities.size(); ++i) {
        q.push({ priorities[i],i });
    }

    sort(priorities.begin(), priorities.end(), greater<>());

    int index = 0;
    while (!q.empty()) {
        pair<int, int>p = q.front();
        q.pop();

        if (p.first == priorities[index]) {
            if (p.second == location) break;
            index++;
            answer++;
        }
        else q.push(p);
    }
    return answer +1;
}

int main()
{
    cout << solution({ 2,1,3,2 }, 2);
}