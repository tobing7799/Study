#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer(2);

void compress(vector<vector<int>>& arr, int x, int y, int size) {
    int value = arr[y][x];
    bool same = true;

    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (arr[i][j] != value) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) answer[value]++;
    else {
        int newsize = size / 2;
        compress(arr, x, y, newsize);
        compress(arr, x + newsize, y, newsize);
        compress(arr, x, y + newsize, newsize);
        compress(arr, x + newsize, y + newsize, newsize);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    compress(arr, 0, 0, arr.size());
    return answer;
}

int main()
{
    for (int n : solution({ {1,1,0,0}, {1,0,0,0}, {1,0,0,1},{1,1,1,1} })) {
        cout << n << " ";
    }
}