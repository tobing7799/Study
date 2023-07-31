#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    return answer = (a + b) % 2 ? 2 * (a + b) : (a % 2 || b % 2) ? a * a + b * b : abs(a - b);
}

int main()
{
    cout << solution(3, 5);
}