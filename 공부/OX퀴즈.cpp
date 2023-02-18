#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;

    for (string s : quiz) {
        int left = 0;
        int right = 0;
        int result = 0;
        char sign;

        int temp = s.find(' ');
        if (temp < s.length())
        {
            left = stoi(s.substr(0, temp));
        }
        s.erase(0,temp+1);

        sign=s.at(0);
        s.erase(0,2);
        temp = s.find(' ');

        if (temp < s.length())
        {
            right = stoi(s.substr(0, temp));
        }
        s.erase(0, temp+3);

        result = stoi(s.substr(0,s.length()));

        switch (sign) {
        case '-':
            if (left - right == result) answer.push_back("O");
            else answer.push_back("X");
            break;
        case '+':
            if (left + right == result) answer.push_back("O");
            else answer.push_back("X");
            break;
        }
    }
    return answer;
}

int main()
{
    vector<string> input{ "19 - 6 = 13", "5 + 66 = 71", "5 - 15 = 63", "3 - 1 = 2" };

    for (string s : solution(input))
    {
        cout << s << endl;
    }
}