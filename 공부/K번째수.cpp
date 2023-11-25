#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (vector<int>v : commands) {
        vector<int>temp = array;
        sort(temp.begin() + (v[0]-1), temp.begin() + (v[1]));
        answer.push_back(temp[v[0]+v[2]-2]);
    }
    return answer;
}

int main()
{
    for (int n : solution({ 1,5,2,6,3,7,4 }, { {2,5,3},{4,4,1},{1,7,3} })) {
        cout << n << ' ';
    }
}