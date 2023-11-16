#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (int n : arr) {
        if (!(n % divisor)) answer.push_back(n);
    }
    sort(answer.begin(), answer.end());
    if (answer.empty())answer.push_back(-1);
    return answer;
}

int main()
{
    for (int n : solution({5,9,7,10},5)) {
        cout << n << '\n';
    }
}