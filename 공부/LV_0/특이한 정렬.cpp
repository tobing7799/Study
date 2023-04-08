#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    sort(numlist.begin(), numlist.end(), std::greater{});
    stable_sort(numlist.begin(), numlist.end(), [n](int a, int b) { return abs(a - n) < abs(b - n); });
    return answer = numlist;
}

int main()
{
    for (int n : solution({ 36, 40, 20, 47, 10, 6, 7000, 10000 }, 30))
    {
        cout << n << "  ";
    }
}