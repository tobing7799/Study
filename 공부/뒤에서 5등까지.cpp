#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    sort(num_list.begin(), num_list.end());
    vector<int> answer(num_list.begin(), num_list.begin()+5);
    return answer;
}

int main()
{
    for (int n : solution({ 12, 4, 15, 46, 38, 1, 14 }))
    {
        cout << n << " ";
    }
}