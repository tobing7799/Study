#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    for (int i = 0; i < n; ++i)
    {
        vector<int>temp(n,0);
        temp[i] = 1;
        answer.push_back(temp);
    }
    return answer;
}

int main()
{
    for (vector<int> v : solution(3))
    {
        for (int n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    }
}