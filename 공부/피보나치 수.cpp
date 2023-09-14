#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;
    int num = 0, temp = 0;

    for (int i = 2; i <= n; ++i) {
        temp = (num + answer) % 1234567;
        num = answer;
        answer = temp;
    }

    return answer;
}

int main()
{
    cout << solution(3);
}