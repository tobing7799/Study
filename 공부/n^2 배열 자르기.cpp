#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (long long i = left; i <= right; ++i) {
        int r, c;
        r = i / n + 1;
        c = i % n + 1;
        answer.push_back(max(r,c));
    }
    return answer;
}

int main()
{
    for (int n : solution(3,2,5)) {
        cout << n << endl;
    }
}