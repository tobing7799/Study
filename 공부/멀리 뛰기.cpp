#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int> dynamic(n + 1, 0);
    dynamic[0] = 1;
    dynamic[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dynamic[i] = (dynamic[i - 1] + dynamic[i - 2]) % 1234567;
    }
    return answer = dynamic[n];
}

int main()
{
    cout << solution(4);
}