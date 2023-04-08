#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    for (int n : array) {
        if (n > height) answer++;
    }
    return answer;
}

int main()
{
    cout << solution({ 149,180,192,170 }, 167);
}