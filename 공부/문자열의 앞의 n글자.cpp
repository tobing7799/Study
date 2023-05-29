#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    return answer = my_string.substr(0,n);
}

int main()
{
    cout << solution("ProgrammerS123", 11);
}