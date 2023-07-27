#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    if (str2.find(str1) != string::npos) answer = 1;
    return answer;
}

int main()
{
    cout << solution("abc", "aabcc");
}