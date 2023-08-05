#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string myString) {
    string answer = "";
    for (char& c : myString)
    {
        if (c < 'l') c = 'l';
    }
    return answer = myString;
}

int main()
{
    cout << solution("abcdevwxyz");
}