#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    answer = *min_element(sides.begin(), sides.end())*2-1;
    return answer;
}

int main()
{
    cout << solution({11, 7 });
}