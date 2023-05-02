#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num, int n) {
    int answer = 0;
    return answer = num % n ? 0 : 1;
}

int main()
{
    cout << solution(98, 2);
}