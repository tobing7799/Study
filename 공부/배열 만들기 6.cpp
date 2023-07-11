#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for (int n : arr)
    {
        if (answer.empty()) answer.push_back(n);
        else if (answer.back() == n) answer.erase(answer.end() - 1);
        else answer.push_back(n);
    }
    if (answer.empty()) answer.push_back(-1);
    return answer;
}

int main()
{
    for (int n : solution({ 0, 1, 1, 1, 0 }))
    {
        cout << n << " ";
    }
}