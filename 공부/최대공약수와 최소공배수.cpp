#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n, m));
    answer.push_back(lcm(n, m));
    return answer;
}

int main()
{
    for (int n : solution(3,12)) {
        cout << n << " ";
    }
}