#include <string>
#include <vector>
#include <iostream>

using namespace std;

int combination(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    else {
        return combination(n - 1, r - 1) + combination(n - 1, r);
    }
}

int solution(int balls, int share) {
    return combination(balls, share);
}

int main()
{
    cout << solution(3, 2);
}