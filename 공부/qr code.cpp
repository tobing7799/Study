#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int q, int r, string code) {
    string answer = "";
    for (int i = 0; i < code.size(); i++)
    {
        if (i % q == r) answer += code[i];
    }
    return answer;
}

int main()
{
    cout << solution(3,1,"qjnwezgrpirldywt");
}