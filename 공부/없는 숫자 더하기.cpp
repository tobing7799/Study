#include <string>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    answer = accumulate(numbers.begin(), numbers.end(), -45)*-1;
    return answer;
}

int main()
{
    cout << solution({ 1,2,3,4,6,7,8,0 });
}