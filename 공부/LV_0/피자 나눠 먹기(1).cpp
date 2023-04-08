#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    return answer = n % 7 ? n / 7 + 1 : n / 7;
}

int main()
{
    cout << solution(15);
}