#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> box, int n) {
    int answer = 1;
    for (int num : box) {
        answer *= num / n;
    }
    return answer;
}

int main()
{
    cout << solution({ 10,8,6 }, 3);
}