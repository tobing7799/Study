#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    if (s.size() % 2) answer = s[s.size() / 2];
    else answer = s.substr(s.size()/2-1, 2);
    return answer;
}

int main()
{
    cout << solution("abcd");
}