#include <string>
#include <iostream>
#include <map>
using namespace std;

int solution(string dirs) {
    int answer = 0;

    pair<int, int>point{0,0};
    map < pair<pair<int, int>, pair<int, int>>, bool >move;

    for (char c : dirs) {
        pair<int, int>next_point = point;
        switch (c) {
        case 'U':
            next_point.second = next_point.second + 1 > 5 ? 5 : next_point.second + 1;
            break;
        case 'R':
            next_point.first = next_point.first + 1 > 5 ? 5 : next_point.first + 1;
            break;
        case 'D':
            next_point.second = next_point.second - 1 < -5 ? -5 : next_point.second - 1;
            break;
        case 'L':
            next_point.first = next_point.first - 1 < -5 ? -5 : next_point.first - 1;
            break;
        }
        if (point != next_point) {
            move[make_pair(point, next_point)] = true;
            move[make_pair(next_point, point)] = true;
            point = next_point;
        }
    }
    return answer = move.size()/2;
}

int main()
{
    cout << solution("DDDDDDDDDDDDUDUDUD");
}