#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    rotate(num_list.begin(), num_list.begin() + n, num_list.end());
    return answer = num_list;
}

int main()
{
    for (int n : solution({ 2, 1, 6 }, 1))
    {
        cout << n << " ";
    }
}