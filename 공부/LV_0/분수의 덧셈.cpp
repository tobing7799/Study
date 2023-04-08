#include <string>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int num1 = numer1 * denom2 + numer2 * denom1;
    int num2 = denom1 * denom2;
    int value = gcd(num1, num2);
    answer.push_back(num1 / value);
    answer.push_back(num2 / value);
    return answer;
}

int main()
{
    for (int n : solution(1, 2, 3, 4)) {
        cout << n << " ";
    }
}