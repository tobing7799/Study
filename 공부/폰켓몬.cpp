#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int , bool> number;

    for (int n : nums) {
        number[n - 1] = true;
    }

    return answer = number.size() < (nums.size()/2) ? number.size() : (nums.size()/2);
}

int main()
{
    cout << solution({3,1,2,3});
}