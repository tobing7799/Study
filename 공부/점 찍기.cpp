#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for (int i = 0; i <= d; i += k) {
        long long distance = (long long)d * d - (long long)i * i;
        answer += floor(sqrt(distance) / k) + 1;
    }
    return answer;
}

int main()
{
    cout << solution(2,4);
}