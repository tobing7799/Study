#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    int p = 0;
    while (1)
    {
        p = myString.find(pat, p);
        if (p == string::npos) break;
        answer++;
        p += 1;
    }
    return answer;
}

int main()
{
    cout << solution("banana", "ana");
}