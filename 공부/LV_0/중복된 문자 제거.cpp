#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (char c : my_string) {
        //if (!answer.contains(c)) answer += c; 프로그래머스는 string에 대한 contains를 지원하지 않는다. c++23을 지원하지 않는듯하다.
        if (answer.find(c) == std::string::npos) answer += c;
    }
    return answer;
}

int main()
{
    cout << solution("people");
}