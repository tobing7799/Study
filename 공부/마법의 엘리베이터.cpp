#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while (storey > 0) {
        int div = storey / 10;
        int rest = storey % 10;
        storey /= 10;
        if (rest > 5 || (rest == 5 && storey % 10 >= 5)) {
            rest = 10 - rest;
            storey++;
        }
        answer += rest;
    }
    return answer;
}

int main()
{
    cout << solution(955);
}