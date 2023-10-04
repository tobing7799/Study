#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long num : numbers) {
        if (num % 2 == 0) answer.push_back(num + 1);
        else answer.push_back(num + (num ^ (num + 1) + 1) / 4 + 1);
    }
    return answer;
}

int main()
{
    for (long long n : solution({ 2,7 })) {
        cout << n << " ";
    }
}