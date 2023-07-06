#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    for (char& c : pat)
    {
        if (c == 'A') c = 'B';
        else c = 'A';
    }
    if (myString.find(pat) != string::npos) answer = 1;
    return answer;
}

int main()
{
    cout << solution("ABBAA", "AABB");
}