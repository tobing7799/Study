#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (char& c : s) {
        if (isalpha(c)) {
            if (isupper(c)) c = c+n > 'Z' ? c+n-'Z'+'A'-1 : c+n;
            else c = c + n > 'z' ? c + n - 'z' + 'a'-1 : c + n;
        }
    }
    return answer = s;
}

int main()
{
    cout << solution("AB", 1);
}