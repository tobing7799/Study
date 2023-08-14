#include <string>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    return answer = (double)accumulate(arr.begin(), arr.end(), 0) / arr.size();
}

int main()
{
    cout << solution({ 1,2,3,4 });
}