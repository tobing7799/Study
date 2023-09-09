#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int num = 0;
    for (char c : s) {
        if (num == 0 && c == ')')
        {
            return false;
        }
        if (c == '(') num++;
        else num--;
    }
    return answer = num == 0 ? true : false;
}

int main()
{
    cout << solution(")()(");
}