#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());

    int n = citations.size();
    int low = 0, high = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        int count = n - (lower_bound(citations.begin(), citations.end(), mid) - citations.begin());
        if (count >= mid)
        {
            answer = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return answer;
}

int main()
{
    cout << solution({3, 0, 6, 1, 5}) << endl;
}