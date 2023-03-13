#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;
    for (int i = 1; ; ++i)
    {
        answer *= i;
        if (answer == n)
        {
            answer = i;
            break;
        }
        else if (answer > n)
        {
            answer = i-1;
            break;
        }
    }
    return answer;
}

int main()
{
    cout << solution(7);
}