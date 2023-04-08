#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    for (char c : my_string) {
        answer.append(n, c);
    }
    return answer;
}

int main()
{
    cout << solution("hello",3);
}