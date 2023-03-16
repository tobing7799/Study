#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    if (direction == "right") rotate(numbers.begin(), numbers.end() - 1, numbers.end());
    else rotate(numbers.begin(), numbers.begin()+1, numbers.end());
    return answer=numbers;
}

int main()
{
    for (int n : solution({ 1,2,3 },"left")) {
        cout << n << "  ";
    }
}