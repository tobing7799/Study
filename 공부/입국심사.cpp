#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());
    long long  max = (long long)times[times.size() - 1] * n;
    long long  min = 1;

    long long p = 0;

    while (min <= max) {
        long long mid = (max + min) / 2;
        p = 0;
        for (long long time : times) {
            p += ((long long)mid / (long long)time);
        }
        if (p >= n) {
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