#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for (auto v : queries) {
        int temp = arr[v[0]];
        arr[v[0]] = arr[v[1]];
        arr[v[1]] = temp;
    }
    return answer = arr;
}

int main()
{
    for (int n : solution({ 0,1,2,3,4 }, { {0,3},{1,2},{1,4} })) {
        cout << n <<" ";
    }
}