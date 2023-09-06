#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string num;
    for (int i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i])) num += s[i];
        else
        {
            switch (s[i]) {
            case 'z':
                num += '0';
                i += 3;
                break;
            case 'o':
                num += '1';
                i += 2;
                break;
            case 't':
                if (s[i + 1] == 'w')
                {
                    num += '2';
                    i += 2;
                }
                else
                {
                    num += '3';
                    i += 4;
                }
                break;
            case 'f':
                if (s[i + 1] == 'o')
                {
                    num += '4';
                    i += 3;
                }
                else
                {
                    num += '5';
                    i += 3;
                }
                break;
            case 's':
                if (s[i + 1] == 'i')
                {
                    num += '6';
                    i += 2;
                }
                else
                {
                    num += '7';
                    i += 4;
                }
                break;
            case 'e':
                num += '8';
                i += 4;
                break;
            case 'n':
                num += '9';
                i += 3;
                break;
            }
        }
    }
    return answer = stoi(num);
}

int main()
{
    cout << solution("23four5six7");
}