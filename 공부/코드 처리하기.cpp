#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string code) {
    string answer = "";
    bool mode = 0;
    for(int i=0; i<code.size(); ++i)
    {
        if (code[i] == '1') mode = !mode;
        else if (!mode && !(i % 2)) answer += code[i];
        else if (mode && (i % 2)) answer += code[i];
    }
    if (!answer.size()) answer = "EMPTY";

    return answer;
}

int main()
{
    cout << solution("abc1abc1abc");
}