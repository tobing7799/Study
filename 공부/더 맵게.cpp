#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> q;
    for (int n : scoville) {
        q.push(n);
    }

    int top = q.top();
    while ((q.size()>1) && (top < K)) {
        q.pop();
        int second = q.top();
        q.pop();

        int sum = top + (second * 2);
        answer++;
        q.push(sum);
        top = q.top();
    }

    if (top < K) answer = -1;
    return answer;
}

int main()
{
    cout << solution({ 1, 2, 3, 9, 10, 12 }, 7);
}