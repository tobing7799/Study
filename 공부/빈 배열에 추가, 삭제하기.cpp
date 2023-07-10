#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (flag[i]) answer.insert(answer.end(), arr[i] * 2, arr[i]);
        else answer.erase(answer.end() - arr[i],answer.end());
    }
    return answer;
}

int main()
{
    for (int n : solution({ 3, 2, 4, 1, 3 },{ true, false, true, false, false }))
    {
        cout << n << " ";
    }
}