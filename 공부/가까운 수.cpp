#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    sort(array.begin(), array.end());
    auto p = find_if(array.begin(), array.end(), [n](int a) {
        if (n < a) return true;
        else return false; });
    if (p == array.begin()) answer = *p;
    else if (*p - n < n - *(p - 1)) answer = *p;
    else answer = *(p - 1);
    return answer;
}

int main()
{
    vector<int> input{ 3, 10, 28 };
    cout << solution(input, 20);
}