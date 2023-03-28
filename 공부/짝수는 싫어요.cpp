#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    for (int i = 1; i <= n; i += 2) {
        answer.push_back(i);
    }
    return answer;
}

int main()
{
    for (int n : solution(10)) {
        cout << n << " ";
    }
}