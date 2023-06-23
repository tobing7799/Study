#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    for (int n : num_list)
    {
        while (n > 1)
        {
            if (n % 2) n = (n - 1) / 2;
            else n /= 2;
            answer++;
        }
    }
    return answer;
}

int main()
{
    cout << solution({ 12,4,15,1,14 });
}