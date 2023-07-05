#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    int lvalue = 0;
    int rvalue = 0;
    char sign = 0;
    stringstream ss(binomial);
    ss >> lvalue;
    ss >> sign;
    ss >> rvalue;
    switch (sign) {
    case '+':
        return lvalue + rvalue;
        break;
    case '-':
        return lvalue - rvalue;
        break;
    case '*':
        return lvalue * rvalue;
        break;
    }

    return answer;
}

int main()
{
    cout << solution("43 + 12");
}