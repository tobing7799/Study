#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2) {
    vector<int> answer(numbers.begin()+num1, numbers.begin()+num2+1);
    return answer;
}

int main()
{
    for (int n : solution({ 1,2,3,4,5 }, 1, 3)) {
        cout << n << " ";
    }
}