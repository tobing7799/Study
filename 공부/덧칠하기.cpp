#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int num = section[0] + m - 1;
    for (int s : section) {
        if (num < s)
        {
            answer++;
            num = s + m - 1;
        }
    }
    return answer;
}

int main()
{
    cout << solution(4,1,{1,2,3,4});
}