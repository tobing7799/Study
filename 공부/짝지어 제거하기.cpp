#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    if (s.empty() || s.size() % 2) return answer;

    stack<char>st;

    for (int i = 0; i < s.size(); ++i) {
        if (st.empty() || st.top() != s[i]) st.push(s[i]);
        else st.pop();
    }

    return answer = st.size()? 0 : 1;
}

int main()
{
    cout << solution("aaaa");
}