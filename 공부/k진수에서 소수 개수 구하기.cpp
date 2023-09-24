#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(long long n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string num;
    string result = "";
    while (n != 0) {
        num += to_string(n % k);
        n /= k;
    }
    reverse(num.begin(), num.end());

    for (auto c : num) {
        if (c == '0') {
            if (result.length() == 0) continue;
            if (isPrime(stol(result)) == true) answer++;
            result = "";
        }
        else result += c;
    }
    if (result.length() != 0 && isPrime(stol(result)) == true) answer++;

    return answer;
}

int main()
{
    cout << solution(437674, 3);
}