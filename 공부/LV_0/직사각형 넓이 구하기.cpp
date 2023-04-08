#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    sort(dots.begin(), dots.end(), [](vector<int>a, vector<int>b) {
        return a[0] > b[0];});
    int x=(*dots.rbegin())[0]- (*dots.begin())[0];
    sort(dots.begin(), dots.end(), [](vector<int>a, vector<int>b) {
        return a[1] > b[1];});
    int y = (*dots.rbegin())[1] - (*dots.begin())[1];
    return answer = x*y;
}

int main()
{
    cout << solution({ {1,1},{2,1},{2,2},{1,2} });
}