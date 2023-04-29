#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    answer = my_string.replace(s, overwrite_string.size(), overwrite_string);
    return answer;
}

int main()
{
    cout << solution("He11oWor1d", "lloWorl", 2);
}