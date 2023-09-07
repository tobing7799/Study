#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<int> intersection;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    set_intersection(lottos.begin(), lottos.end(), win_nums.begin(), win_nums.end(), back_inserter(intersection));
    int best = 7 - intersection.size() - count(lottos.begin(), lottos.end(), 0);
    int worst = 7 - intersection.size();
    if (best == 7) answer.push_back(6);
    else answer.push_back(best);
    if (worst == 7) answer.push_back(6);
    else answer.push_back(worst);
    return answer;
}

int main()
{
    for (int n : solution({ 44, 1, 0, 0, 31, 25 }, { 31, 10, 45, 1, 6, 19 })) {
        cout << n << " ";
    }
}