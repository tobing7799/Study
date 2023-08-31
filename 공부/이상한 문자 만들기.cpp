#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = s;
    int count = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        count++;
        if (answer[i] == ' ') count = 0;
        else if (count % 2) answer[i] = toupper(answer[i]);
        else answer[i] = tolower(answer[i]);
    }
    return answer;
}

int main()
{
    cout << solution("try hello world");
}