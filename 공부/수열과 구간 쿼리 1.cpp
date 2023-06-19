#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for (vector<int> v : queries)
    {
        for_each(arr.begin() + v[0], arr.begin() + v[1]+1, [](int& value) { value += 1; });
    }
    return answer = arr;
}

int main()
{
    for (int n : solution({ 0,1,2,3,4 }, { {0,1},{1,2}, {2,3} }))
    {
        cout << n << " ";
    }
}