#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b) {
    int answer = 2;
    int num = 0;
    if (a % b == 0) return 1;
    for (int i=a; i > 1; --i)
    {
        if (b % i==0 && a % i ==0)
        {
            num = i;
            a /= num;
            b /= num;
            break;
        }
    }
    while (1)
    {
        if (b % 2 == 0) b /= 2;
        else if (b % 5 == 0) b /= 5;
        else break;
    }
    if (b == 1) answer = 1;
    else answer = 2;
    return answer;
}

int main()
{
    cout << solution(43, 7);
}