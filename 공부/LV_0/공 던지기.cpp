#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    int index =(k-1)*2 % numbers.size();
    return answer=numbers[index];
}

int main()
{
    cout << solution({1,2,3,4},2);
}