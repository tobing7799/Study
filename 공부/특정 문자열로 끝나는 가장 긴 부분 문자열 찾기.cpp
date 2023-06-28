#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    int p = 0;
    while (1)
    {
        p = myString.find(pat, p);
        if (p == string::npos) break;
        answer = myString.substr(0, p + pat.size());
        p += pat.size();
    }
    return answer;
}

int main()
{
    cout << solution("AbCdEFG", "dE");
}