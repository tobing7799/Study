#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for (int& n : arr)
    {
        if (50 <= n && !(n % 2) ) n /= 2;
        else if (50 > n && n % 2) n *= 2;
    }
    return answer = arr;
}

int main()
{
    for (int n : solution({ 1, 2, 3, 100, 99, 98 }))
    {
        cout << n << " ";
    }
}