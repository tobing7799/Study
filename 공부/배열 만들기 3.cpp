#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    vector<int> v1{ arr.begin() + intervals[0][0], arr.begin()+intervals[0][1]+1 };
    vector<int> v2{ arr.begin() + intervals[1][0], arr.begin()+intervals[1][1]+1 };
    for (int n : v1) {
        answer.push_back(n);
    }
    for (int n : v2) {
        answer.push_back(n);
    }
    return answer;
}

int main()
{
    for (int n : solution({ 1, 2, 3, 4, 5 }, { {1,3}, {0,4} }))
    {
        cout << n << " ";
    }
}