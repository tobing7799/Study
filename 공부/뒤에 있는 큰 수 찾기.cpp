#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack <int > s;
    for (int i = 0; i < numbers.size(); ++i) {
        while (!s.empty() && numbers[i] > numbers[s.top()]) {
            int idx = s.top();
            s.pop();
            answer[idx] = numbers[i];
        }
        s.push(i);
    }
    return answer;
}

int main()
{
    for (int n : solution({ 9, 1, 5, 3, 6, 2 })) {
        cout << n << " ";
    }
}

//  4   3   5   6