#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Countbits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int solution(int n) {
    int num = Countbits(n);
    while (1) {
        n++;
        if (num == Countbits(n)) return n;
    }
}

int main()
{
    cout << solution(78);
}