#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    if (myString.size() < pat.size()) answer = 0;
    else
    {
        for (char& c : myString)
        {
            c = tolower(c);
        }
        for (char& c : pat)
        {
            c = tolower(c);
        }
        if (myString.find(pat) != string::npos) answer = 1;
    }
    return answer;
}

int main()
{
    cout << solution("AbCdEfG", "aBc");
}