#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;

    long long total = money;
    for (int i = 1; i <= count; ++i)
    {
        total = total - i * price;
    }
    if (total > -1) answer = 0;
    else answer = total * -1;
    return answer;
}

int main()
{
    cout << solution(3, 20, 4);
}