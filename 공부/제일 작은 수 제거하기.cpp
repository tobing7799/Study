#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (arr.size() == 1) return vector<int>{ -1};
    arr.erase(min_element(arr.begin(), arr.end()));
    return answer = arr;
}

int main()
{
    for (int n : solution({4,3,2,1})) {
        cout << n << endl;
    }
}