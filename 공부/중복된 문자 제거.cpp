#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (char c : my_string) {
        //if (!answer.contains(c)) answer += c; ���α׷��ӽ��� string�� ���� contains�� �������� �ʴ´�. c++23�� �������� �ʴµ��ϴ�.
        if (answer.find(c) == std::string::npos) answer += c;
    }
    return answer;
}

int main()
{
    cout << solution("people");
}