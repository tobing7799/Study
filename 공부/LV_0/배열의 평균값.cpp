#include <string>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    return answer = static_cast<double>(accumulate(numbers.begin(), numbers.end(),0)) / numbers.size();
}

int main()
{
    cout << solution({ 1,2,3,4,5,6,7,8,9,10 });
}