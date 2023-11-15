#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string num;
    num = to_string(n);
    sort(num.begin(), num.end(), greater<>());
    return answer = stoll(num);
}

int main()
{
    cout << solution(118372);
}