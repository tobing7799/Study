#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    stringstream str(my_string);
    string s;
    while (str >> s)
    {
        answer.push_back(s);
    }
    return answer;
}

int main()
{
    for (string s : solution("    programmers  "))
    {
        cout << s << " ";
    }
}