#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for (int n : arr)
    {
        for (int i = n; i > 0; i--)
        {
            answer.push_back(n);
        }
    }
    return answer;
}

int main()
{
    for (int n : solution({ 5, 1, 4 }))
    {
        cout << n << " ";
    }
}