#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (char c : my_string) {
        switch (c) {
        case 'a':case 'e': case 'i': case 'o': case 'u':
            break;
        default:
            answer += c;
            break;
        }
    }
    return answer;
}

int main()
{
    cout << solution("bus");
}