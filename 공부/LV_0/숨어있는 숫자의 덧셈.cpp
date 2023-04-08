#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    string temp = "";
    for (char c : my_string) {
        if (isdigit(c)) temp += c;
        else
        {
            if(!temp.empty()) answer += stoi(temp);
            temp.clear();
        }
    }
    if (!temp.empty()) answer += stoi(temp);
    return answer;
}

int main()
{
    cout << solution("aAb1B2cC34oOp");
}