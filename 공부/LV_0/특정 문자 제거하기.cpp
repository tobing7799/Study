#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    std::copy_if(my_string.begin(), my_string.end(), std::back_inserter(answer), [&](char c) {
        return c != letter[0]; });

    return answer;
}

int main()
{
    cout << solution("abcdef","f");
}