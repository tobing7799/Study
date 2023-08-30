#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Count(int number) {
    int count = 0;

    for (int i = 1; i <= number; ++i)
    {
        if (number % i == 0) count++;
    }

    return count;
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; ++i)
    {
        if (Count(i) % 2 == 0) answer += i;
        else answer -= i;
    }
    return answer;
}

int main()
{
    cout << solution(13,17);
}