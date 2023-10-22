#include <iostream>


using namespace std;


int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

long long solution(int w, int h) {
    long long answer = -1;
    long long gcd = static_cast<long long>(GCD(w, h));
    long long total = static_cast<long long>(w) * h;
    long long remove = (w / gcd + h / gcd - 1) * gcd;

    return answer = total - remove;
}

int main()
{
    cout << solution(8, 12);
}