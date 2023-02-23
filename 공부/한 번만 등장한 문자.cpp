#include <string>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    for (char c : s) {
        if (count(s.begin(), s.end(), c) < 2)
            answer += c;
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    cout << solution("abcabcadc");
}