#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, string alp) {
    string answer = "";
    for (char& c : my_string)
    {
        if (c == alp[0]) c = toupper(c);
    }
    return answer = my_string;
}

int main()
{
    cout << solution("programmers", "p");
}