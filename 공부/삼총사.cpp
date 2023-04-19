#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int n = number.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (number[i] + number[j] + number[k] == 0) {
                    answer++;
                }
            }
        }
    }
    return answer;
}

int main()
{
    cout << solution({ -2,3,0,2,-5 });
}