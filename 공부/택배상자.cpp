#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> belt;
    int index = 0;
    for (int i = 1; i <= order.size(); ++i) {
        belt.push(i);
        while (belt.size() && belt.top() == order[index]) {
            belt.pop();
            index++;
        }
    }
    return answer = index;
}

int main()
{
    cout << solution({ 5, 4, 3, 2, 1 });
}