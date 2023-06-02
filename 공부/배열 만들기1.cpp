#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int k) {
    vector<int> answer;
    for (int i = k; i <= n; i += k)
    {
        answer.push_back(i);
    }
    return answer;
}

int main()
{
    for (int n : solution(10, 3)) {
        cout << n << " ";
    }
}