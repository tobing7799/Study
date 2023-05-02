#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int number, int n, int m) {
    int answer = 0;
    return answer = number%n==0 && number%m==0 ? 1 : 0;
}

int main()
{
    cout << solution(60, 2, 3);
}