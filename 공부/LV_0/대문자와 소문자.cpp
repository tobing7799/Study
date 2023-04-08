#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (char& c : my_string) {
        if (isupper(c))
            c=tolower(c);
        else
            c=toupper(c);
    }
    return answer=my_string;
}

int main()
{
    cout << solution("abCdEfghIJ");
}