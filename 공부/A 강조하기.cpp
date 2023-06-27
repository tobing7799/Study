#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string myString) {
    string answer = "";

    for (char& c : myString)
    {
        if (c == 'a') c = 'A';
        else if (isupper(c) && c != 'A' && isalpha(c)) c = tolower(c);
    }
    return answer = myString;
}

int main()
{
    cout << solution("abstract algebra");
}