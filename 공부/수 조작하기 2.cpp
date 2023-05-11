#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    int sub = 0;
    for (int i = 1; i < numLog.size(); ++i)
    {
        sub = numLog[i] - numLog[i - 1];
        if (sub == 1) answer += 'w';
        else if (sub == -1) answer += 's';
        else if (sub == 10) answer += 'd';
        else answer += 'a';
    }
    return answer;
}

int main()
{
    cout << solution({ 0,1,0,10,0,1,0,10,0,-1,-2,-1 });
}