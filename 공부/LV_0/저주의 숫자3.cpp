#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    std::vector<int> v(100);
    int val = 1;
    std::generate(v.begin(), v.end(), [&]() {
        while (val % 3 == 0 || to_string(val).find('3') != string::npos) {
            ++val;
        }
    return val++;});

    return answer = v[n-1];
}

int main()
{
    cout << solution(40);
}