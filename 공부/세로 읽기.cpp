#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    for (int i = c-1; i < my_string.size(); i += m) {
        answer += my_string[i];
    }
    return answer;
}

int main()
{
    cout << solution("ihrhbakrfpndopljhygc", 4, 2);
}