#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    pair<vector<int>, int> one{ {1,2,3,4,5},0 };
    pair<vector<int>, int> two{ {2,1,2,3,2,4,2,5 },0 };
    pair<vector<int>, int> three{ {3,3,1,1,2,2,4,4,5,5},0 };
    int max = 0;

    for (int i = 0; i < answers.size(); ++i) {
        if (one.first[i % one.first.size()] == answers[i]) one.second++;
        if (two.first[i % two.first.size()] == answers[i]) two.second++;
        if (three.first[i % three.first.size()] == answers[i]) three.second++;

        if (max < one.second) max = one.second;
        if (max < two.second) max = two.second;
        if (max < three.second) max = three.second;
    }

    if (max == one.second) answer.push_back(1);
    if (max == two.second) answer.push_back(2);
    if (max == three.second) answer.push_back(3);

    return answer;
}

int main()
{
    for (int n : solution({1,2,3,4,5})) {
        cout << n << ' ';
    }
}