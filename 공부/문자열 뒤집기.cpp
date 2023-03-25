#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    reverse(my_string.begin(), my_string.end());
    return answer = my_string;
}

int main()
{
    cout << solution("jaron");
}