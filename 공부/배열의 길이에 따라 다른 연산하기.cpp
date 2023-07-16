#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    vector<int> answer;
    for (int i = arr.size() % 2 == 0 ? 1 : 0; i < arr.size(); i += 2)
    {
        arr[i] += n;
    }
    return answer = arr;
}

int main()
{
    for (int n : solution({ 49, 12, 100, 276, 33 }, 27))
    {
        cout << n << " ";
    }
}