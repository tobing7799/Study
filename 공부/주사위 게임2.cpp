#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int c) {
    int answer = 0;
    return answer = a != b && a != c && b != c ? a + b + c : ((a == b && a != c) || (b == c && a != b) || (a == c && a != b)) ? ((a + b + c) * (a * a + b * b + c * c)) : ((a + b + c) * (a * a + b * b + c * c) * (a * a * a + b * b * b + c * c * c));
}

int main()
{
    cout << solution(2, 6, 1);
}