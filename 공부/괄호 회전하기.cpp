#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(string s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') st.push(ch);
        else
        {
            if (st.empty()) return false;
            char top = st.top();
            if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{'))  st.pop();
            else return false;
        }
    }
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    int len = s.length();

    for (int i = 0; i < len; ++i) {
        string rotated = s.substr(i) + s.substr(0, i);
        if (isBalanced(rotated)) {
            answer++;
        }
    }

    return answer;
}

int main()
{
    cout << solution("}]()[{");
}