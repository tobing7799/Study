#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());
    int max = times[times.size() - 1] * n;
    int min = 1;

    int p = 0;

    while (min <= max) {
        int mid = (max + min) / 2;
        p = 0;
        for (int time : times) {
            p += mid / time;
        }
        if (p >= n) { //정답을 찾을 코드로
            answer = mid;

            max = mid - 1;
        }
        else {
            min = mid + 1;
        }
    }
    return answer;
}

int main()
{
    cout << solution(6, { 7,10 });
}