#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double num = sqrt(n);
    if (int(num) == (double)num) answer = pow(num + 1, 2);
    else answer = -1;
    return answer;
}

int main()
{
    cout << solution(121);
}