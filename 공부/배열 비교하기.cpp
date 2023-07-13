#include <string>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int answer = 0;
    if (arr1.size() < arr2.size()) answer = -1;
    else if (arr1.size() == arr2.size())
    {
        int n1 = accumulate(arr1.begin(), arr1.end(), 0);
        int n2 = accumulate(arr2.begin(), arr2.end(), 0);
        if (n1 < n2) answer = -1;
        else if (n1 == n2) answer = 0;
        else answer = 1;
    }
    else answer = 1;
    return answer;
}

int main()
{
    cout << solution({ 49, 13 },{ 70, 11, 2 });
}