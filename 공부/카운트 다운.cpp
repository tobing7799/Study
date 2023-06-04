#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int start, int end) {
    vector<int> answer;
    answer.reserve(start - end);
    while (start >= end) {
        answer.push_back(start);
        start--;
    }
    return answer;
}

int main()
{
    for (int n : solution(10, 3)) {
        cout << n << " ";
    }
}