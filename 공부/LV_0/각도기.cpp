#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int angle) {
    int answer = 0;
    return answer = (angle > 0 && angle < 90) ? 1 : (angle == 90) ? 2 : (angle > 90 && angle < 180) ? 3 : 4;
}

int main()
{
    cout << solution(70);
}