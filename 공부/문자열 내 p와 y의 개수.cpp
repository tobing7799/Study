#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int countP=0;
    int countY=0;
    for (char c : s) {
        if (tolower(c) == 'p') ++countP;
        else if (tolower(c) == 'y')++countY;
    }
    return answer = countP == countY ? true : false;
}

int main()
{
    cout << solution("pPoooyY");
}