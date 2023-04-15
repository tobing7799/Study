#include <string>
#include <vector>
#include <iostream>

using namespace std;

int GetDivisors(int n)
{
    int divisors = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors++;
            if (i != n / i) {
                divisors++;
            }
        }
    }
    return divisors;
}

int solution(int number, int limit, int power) {
    int answer = 0;

    for (int i = 1; i <= number; ++i)
    {
        int n = GetDivisors(i);
        if (n > limit) n = power;
        answer += n;
    }
    
    return answer;
}

int main()
{
    cout << solution(10, 3, 2);
}