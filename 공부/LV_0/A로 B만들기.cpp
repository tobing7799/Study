#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string before, string after) {
    int answer = 0;
    sort(before.begin(), before.end());
    sort(after.begin(), after.end());
    if (after == before) answer = 1;
    else answer = 0;
    return answer;
}

int main()
{
    cout << solution("olleh", "hello");
}