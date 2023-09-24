#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n) {

    queue<pair<int, int>> q;
    unordered_set<int> visited;

    q.push({ x, 0 });
    visited.insert(x);

    while (!q.empty()) {
        int current = q.front().first;
        int operation = q.front().second;
        q.pop();

        if (current == y) {
            return operation;
        }

        int next = current + n;
        if (next <= y && visited.find(next) == visited.end()) {
            q.push({ next, operation + 1 });
            visited.insert(next);
        }

        next = current * 2;
        if (next <= y && visited.find(next) == visited.end()) {
            q.push({ next, operation + 1 });
            visited.insert(next);
        }

        next = current * 3;
        if (next <= y && visited.find(next) == visited.end()) {
            q.push({ next, operation + 1 });
            visited.insert(next);
        }
    }

    return -1;
}


int main()
{
    cout << solution(10, 40, 5);
}