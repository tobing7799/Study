#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    return answer = arr;
}

int main()
{
    for (int n : solution({1,1,3,3,0,1,1})) {
        cout << n << ' ';
    }

}