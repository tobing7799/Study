#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int divide = 0;
    while(n>=a)
    {
        divide = n % a;
        n = n / a;
        answer = answer + (n * b);
        n = n*b+divide;
    }
    return answer;
}

int main()
{
    cout << solution(3, 1, 20);
}