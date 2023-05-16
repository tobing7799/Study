#include <string>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

vector<int> solution(int start, int end) {
    vector<int> answer(end-start+1);
    iota(answer.begin(), answer.end(), start);
    return answer;
}

int main()
{
    for (int n : solution(3, 10)) {
        cout << n << " ";
    }
}