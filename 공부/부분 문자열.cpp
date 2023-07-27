#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string, string target) {
    int answer = 0;
    if (my_string.find(target) != string::npos) answer = 1;
    return answer;
}

int main()
{
    cout << solution("banana", "ana");
}