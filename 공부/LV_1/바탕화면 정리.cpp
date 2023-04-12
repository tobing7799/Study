#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<pair<int, int>> coordinates;
    for (int y = 0; y < wallpaper.size(); ++y)
    {
        for (int x = 0; x < wallpaper[y].size(); ++x)
        {
            if (wallpaper[y][x] == '#') coordinates.push_back(make_pair(y, x));
        }
    }
    pair<int, int> lu{ wallpaper.size(),wallpaper[0].size()};
    pair<int, int> rd{0,0};
    for (auto [x, y] : coordinates) {
        if (x < lu.first) lu.first = x;
        if (x > rd.first) rd.first = x;
        if (y < lu.second) lu.second = y;
        if (y > rd.second) rd.second = y;
    }
    answer.push_back(lu.first);
    answer.push_back(lu.second);
    answer.push_back(rd.first+1);
    answer.push_back(rd.second + 1);
    return answer;
}

int main()
{
    for (int n : solution({ ".#...", "..#..", "...#." })) {
        cout << n <<" ";
    }
}