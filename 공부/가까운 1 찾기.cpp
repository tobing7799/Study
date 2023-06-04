#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> arr, int idx) {
    int answer = 0;
    auto p = find(arr.begin() + idx, arr.end(), 1);
    if (p == arr.end()) return answer = -1;
    return answer = distance(arr.begin(),p);
}

int main()
{
    cout << solution({ 0,0,0,1 }, 1);
}