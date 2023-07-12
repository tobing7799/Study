#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer(k, -1);
    int p = 0;
    for (int n : arr)
    {
        if (k == 0) break;
        if (find(answer.begin(), answer.end(), n) == answer.end())
        {
            answer[p] = n;
            p++;
            k--;
        }
    }
    return answer;
}

int main()
{
    for (int n : solution({ 0, 1, 0, 1 }, 4))
    {
        cout << n << " ";
    }
}