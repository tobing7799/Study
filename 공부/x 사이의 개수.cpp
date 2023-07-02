#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    int n = 0;
    for (char c : myString)
    {
        if (c != 'x') n++;
        else
        {
            answer.push_back(n);
            n = 0;
        }
    }
    answer.push_back(n);
    return answer;
}

int main()
{
    for (int n : solution("oxooxoxxox"))
    {
        cout << n << " ";
    }
}