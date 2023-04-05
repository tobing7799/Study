#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    answer = count(array.begin(), array.end(), n);
    return answer;
}

int main()
{
    cout << solution({1,1,2,3,4,5},1);
}