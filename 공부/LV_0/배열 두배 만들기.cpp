#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer = numbers;
    for (int& n : answer) {
        n *= 2;
    }
    return answer;
}

int main()
{
    for (int n : solution({ 1,2,3,4,5 })) {
        cout << n << " ";
    }
}