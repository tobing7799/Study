#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 2;
    if (str1.contains(str2)) return 1;

    return answer;
}

int main()
{
    string input1 = "ab6CDE443fgh22iJKlmn1o";
    string input2 = "6CD";
    cout << solution(input1, input2);
}

/*
int solution(string str1, string str2) {
    int answer = 2;
    if (str1.find(str2)<str1.length())
            return 1;
    return answer;
}
프로그래머스는 최신 c++지원을 하지 않아서 find로 제출했다.
*/