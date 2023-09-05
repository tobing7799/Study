#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int x = 0;
    int y = 0;
    for (vector<int> v : sizes)
    {
        int max = *max_element(v.begin(), v.end());
        int min = *min_element(v.begin(), v.end());
        x = x < max ? max : x;
        y = y < min ? min : y;
    }
    return answer = x*y;
}

int main()
{
    cout << solution({ {60, 50} ,{30, 70},{60, 30},{80, 40} });
}