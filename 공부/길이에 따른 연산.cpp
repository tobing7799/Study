#include <string>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    if (num_list.size() > 10) answer = accumulate(num_list.begin(), num_list.end(), 0);
    else answer = accumulate(num_list.begin(), num_list.end(), 1, multiplies<int>());
    return answer;
}

int main()
{
    cout << solution({ 3,4,5,2,5,4,6,7,3,7,2,2,1 });
}