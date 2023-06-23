#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    vector<int> prev;
    while (1)
    {
        prev = arr;
        for (int &n : arr)
        {
            if (50 <= n && !(n % 2)) n /= 2;
            else if (50 > n && n % 2) n = n * 2 + 1;
        }
        if (arr == prev) break;
        answer++;
    }
    return answer;
}

int main()
{
    cout << solution({ 1,2,3,100,99,98 });
}