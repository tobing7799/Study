#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int length = arr.size();
    int n = 1;
    while (n < length) n *= 2;
    arr.resize(n, 0);
    return answer = arr;
}

int main()
{
    for (int n : solution({ 1, 2, 3, 4, 5, 6 }))
    {
        cout << n << " ";
    }
}