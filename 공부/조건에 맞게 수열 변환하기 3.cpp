#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    if(k%2) transform(arr.begin(), arr.end(), arr.begin(), [&k](int& a) { return a * k; });
    else transform(arr.begin(), arr.end(), arr.begin(), [&k](int& a) { return a + k; });
    return answer = arr;
}

int main()
{
    for (int n : solution({ 1, 2, 3, 100, 99, 98 },3))
    {
        cout << n << " ";
    }
}