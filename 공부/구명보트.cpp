#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    deque<int> dq{people.begin(), people.end()};
    while (!dq.empty()) {
        if (dq.front() + dq.back() <= limit && dq.size()>1) {
            dq.pop_front();
            dq.pop_back();
            answer++;
        }
        else {
            dq.pop_back();
            answer++;
        }
    }
    return answer;
}

int main()
{
    cout << solution({70,50,80,50} , 100);
}