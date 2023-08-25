#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end(), greater());
    return answer = s;
}

int main()
{
    cout << solution("Zbcdefg");
}