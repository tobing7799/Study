#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int>stack;

    for (int i = 0; i < prices.size(); ++i) {
        while (!stack.empty() && prices[i] < prices[stack.top()]) {
            int index = stack.top();
            stack.pop();
            answer[index] = i - index;
        }
        stack.push(i);
    }

    while (!stack.empty()) {
        int index = stack.top();
        stack.pop();
        answer[index] = prices.size() - 1 - index;
    }

    return answer;
}

int main()
{
    for (int n : solution({ 1, 2, 3, 2, 3 })) {
        cout << n << " ";
    }
}