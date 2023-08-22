#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string number = to_string(n);
    reverse(number.begin(), number.end());
    for (char c : number)
    {
        answer.push_back(c - '0');
    }
    return answer;
}

int main()
{
    for (int n : solution(12345))
    {
        cout << n << endl;
    }
}