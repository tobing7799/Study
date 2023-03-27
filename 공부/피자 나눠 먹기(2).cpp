#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num = 0;
    for (int i = 1; ; ++i) {
        num = n * i;
        if (!(num % 6)) {
            answer = num / 6;
            break;
        }
    }
    return answer;
}

int main()
{
    cout << solution(10);
}