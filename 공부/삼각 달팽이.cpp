#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> snail;
    int size = 0;
    for (int i = 1; i <= n; ++i) {
        snail.push_back(vector<int>(i,0));
        size += i;
    }
    
    int x = 0, y = 0, count = 1;

    while (count != size+1) {
        while (x < n && snail[x][y] == 0) 
            snail[x++][y] = count++;
        x--, y++;
        while (y < n && snail[x][y] == 0) 
            snail[x][y++] = count++;
        y-=2 , x--;
        while (snail[x][y] == 0) 
            snail[x--][y--] = count++;
        x+=2, y++;
    }

    for (int i = 0; i < snail.size(); ++i) {
        for (int j = 0; j < snail[i].size(); ++j) {
            answer.push_back(snail[i][j]);
        }
    }
    return answer;
}

int main()
{
    for (int n : solution(4)) {
        cout << n << " ";
    }
}