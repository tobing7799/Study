#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    string word="";
    sort(spell.begin(), spell.end());
    for (string c : spell)
    {
        word += c;
    }

    for (string &s : dic)
    {
        sort(s.begin(), s.end());
        if (word == s)
        {
            answer = 1;
            break;
        }
    }
    return answer;
}

int main()
{
    cout << solution({"p","o","s"}, { "sod", "eocd", "qixm", "adio", "soo" });
}