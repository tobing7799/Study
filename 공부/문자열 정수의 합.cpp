#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    for (char c : num_str)
    {
        answer += c - '0';
    }
    return answer;
}

int main()
{
    cout << solution("123456789");
}