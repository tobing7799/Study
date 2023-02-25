#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int order) {
    int answer = 0;
    int temp = 0;
    while (order>0) {
        temp = order % 10;
        order /= 10;
        if (temp % 3 == 0 && temp!=0)
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    cout << solution(29423);
}