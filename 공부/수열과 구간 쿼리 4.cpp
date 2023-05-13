#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for (auto v : queries) {
        for (int i = v[0]; i <= v[1]; ++i)
        {
            if (i % v[2] == 0) arr[i]++;
        }
    }
    return answer = arr;
}

int main()
{
    for (int n : solution({ 0,1,2,4,3 }, { {0,4,1}, {0,3,2},{0,3,3} })) {
        cout << n << " ";
    }
}