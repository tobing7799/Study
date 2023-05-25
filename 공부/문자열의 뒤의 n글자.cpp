#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    return answer = my_string.substr(my_string.size()-n,my_string.size());
}

int main()
{
    cout << solution("P", 1);
}