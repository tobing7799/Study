#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;
    return answer *= ((n / 2) * ((n / 2) + 1));
}

int main()
{
    cout << solution(10);
}