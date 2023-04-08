#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    return answer = *numbers.rbegin() * *(numbers.rbegin()+1);
}

int main()
{
    cout << solution({ 1, 2, 3, 4, 5 });
}