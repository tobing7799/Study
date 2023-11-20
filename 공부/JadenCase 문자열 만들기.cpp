#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    
    string temp;
    stringstream ss{ s };
    while (ss >> temp) {
        for (char& c : temp) {
            c = tolower(c);
        }
        temp[0] = toupper(temp[0]);
        int spaceCount = 0;
        if (ss.peek() == ' ' || ss.peek() == '\t') {
            while (isspace(ss.peek())) {
                ss.get();
                spaceCount++;
            }
        }
        answer += temp;
        for (int i = 0; i < spaceCount; ++i) {
            answer += " ";
        }
    }
    return answer;
}

int main()
{
    cout << solution("3people unFollowed me");
}