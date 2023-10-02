#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (string s : skill_trees) {
        string temp = "";
        for (char c : s) {
            if (skill.find(c) != string::npos) temp += c;
        }
        if (skill.find(temp) == 0) answer++;
    }
    return answer;
}

int main()
{
    cout << solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" });
}