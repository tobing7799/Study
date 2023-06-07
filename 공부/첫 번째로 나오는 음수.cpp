#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list) {
    int answer = -1;
    auto p = find_if(num_list.begin(), num_list.end(), [](const int n) { return n < 0; });
    if (p != num_list.end()) answer = distance(num_list.begin(), p);
    return answer;
}

int main()
{
    cout << solution({ 12, 4, 15, 46, 38, -2, 15 });
}