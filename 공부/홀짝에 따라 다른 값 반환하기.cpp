#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = n%2; i <= n; i += 2)
    {
        if (n % 2 == 0) answer += (i * i);
        else answer += i;
    }
    return answer;
}

int main()
{
    cout << solution(7);
}