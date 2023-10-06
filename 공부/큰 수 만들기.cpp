#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char>s;
    while (number.size() && k) {
        s.push(number.front());
        number.erase(0,1);
        while ( !(s.empty() || number.empty()) && s.top() < number.front() && k) {
            s.pop();
            k--;
        }
    }
    while (k) {
        s.pop();
        k--;
    }
    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer +=number;
}

int main()
{
    cout << solution("987654321", 5);
}

//447711177771111