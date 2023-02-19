#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer = numlist;
    answer.erase(remove_if(answer.begin(), answer.end(), [n](int a) {
        return (a % n); }),answer.end());
    return answer;
}

int main()
{
    vector<int> temp{ 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    auto p = solution(3, temp);
    for (int a : p) {
        cout << a << endl;;
    }
}