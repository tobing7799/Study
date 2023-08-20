#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    for (int i = a > b ? b : a; i <= (a > b ? a : b); ++i) answer += i;
    return answer;
}

int main()
{
    cout << solution(3, 5);
}