#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for (char c : my_string) {
        if (isdigit(c)) answer += c - '0';
    }
    return answer;
}

int main()
{
    cout << solution("aAb1B2cC34oOp");
}