#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size());
    for (int i = 0; i < arr1.size(); ++i) {
        for (int j = 0; j < arr1[i].size(); ++j) {
            answer[i].push_back(arr1[i][j] + arr2[i][j]);
        }
    }
    return answer;
}

int main()
{
    for (vector<int> v : solution({ {1,2},{2,3} }, { {3,4,},{5,6} })) {
        for (int n : v) {
            cout << n<<" ";
        }
        cout << endl;
    }
}