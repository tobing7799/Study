#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    stringstream str(s);
    int n = 0;
    char c = 0;

    while (str>>c) {
        if (isdigit(c)||c=='-')
        {
            str.unget();
            str >> n;
            answer += n;
        }
        else answer -= n;
    }

    return answer;
}

int main()
{
    cout << solution("10 20 30 40");
}