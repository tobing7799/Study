#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    for (int n : arr)
    {
        if (find(delete_list.begin(), delete_list.end(), n) == delete_list.end()) answer.push_back(n);
    }
    return answer;
}

int main()
{
    for (int n : solution({ 293, 1000, 395, 678, 94 },{ 94, 777, 104, 1000, 1, 12 }))
    {
        cout << n << " ";
    }
}