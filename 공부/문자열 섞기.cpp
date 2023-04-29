#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    for (int i = 0; i < str1.size(); ++i)
    {
        answer += str1[i];
        answer += str2[i];
    }
    return answer;
}

int main()
{
    cout << solution("aaaaa", "bbbbb");
}