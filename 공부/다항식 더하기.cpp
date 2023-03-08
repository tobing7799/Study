#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    string num="";
    int x = 0;
    int c = 0;
    while (polynomial.size()) {
        if (isdigit(polynomial.front()))
        {
            num += polynomial.front();
        }
        else if (polynomial.front() == 'x')
        {
            if (num.empty()) x += 1;
            else x += stoi(num);
            num.clear();
        }
        else if (polynomial.front() == '+')
        {
            if (!num.empty()) c += stoi(num);
            num.clear();
        }
        polynomial.erase(0,1);
        if (!num.empty() && !polynomial.size()) c += stoi(num);
    }

    if(x==1) answer += "x";
    else if(x)answer += to_string(x) + "x";
    if (c)
    {
        if (x) answer += (" + " + to_string(c));
        else answer += to_string(c);
    }
    return answer;
}

int main()
{
    cout << solution("1 + 3 + 3x + 10x + 10 + 23");
}