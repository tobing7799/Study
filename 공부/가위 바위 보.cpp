#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string rsp) {
    string answer = "";
    for (char c : rsp) {
        if (c == '0') answer += '5';
        else if (c == '2')answer += '0';
        else answer += '2';
    }
    return answer;
}

int main()
{
    cout << solution("2");
}