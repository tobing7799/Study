#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool Check(vector<string>& v)
{
    vector<vector<int>> result(5, vector<int>(5,0));
    queue<pair<int, int>> tables;
    const int dx[] = { 1,0,-1,0 };
    const int dy[] = { 0,1,0,-1 };
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (v[i][j] == 'P') {
                result[i][j]++;
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
                        if (v[nx][ny] != 'X') result[nx][ny]++;
                    }
                }
            }
        }
    }
    for (vector<int>& v : result) {
        for (int n : v) {
            if (n > 1)return true;
        }
    }
    return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (vector<string>v : places) {
        if (Check(v)) answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}

int main()
{
    for (int n : solution({ {"POOPO", "OOOOO", "OOOXP", "OPOPX", "OOOOO"},{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} })) {
        cout << n << " ";
    }
}

//bool Check(vector<string>& v) //³ª»Û¿¹
//{
//    queue<pair<int, int>> tables;
//    const int dx[] = { 1,0,-1,0 };
//    const int dy[] = { 0,1,0,-1 };
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            if (v[i][j] == 'P') {
//                for (int k = 0; k < 4; ++k) {
//                    int nx = i + dx[k];
//                    int ny = j + dy[k];
//                    if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
//                        if (v[nx][ny] == 'P') {
//                            return true;
//                        }
//                        else if (v[nx][ny] == 'O') {
//                            if (dx[k] != 0) {
//                                for (int t = 1; t < 4; t += 2) {
//                                    int ty = ny + dy[t];
//                                    if (0 <= ty && ty < 5) {
//                                        if (v[nx][ty] == 'P') {
//                                            return true;
//                                        }
//                                    }
//                                }
//                            }
//                            else {
//                                for (int t = 0; t < 4; t += 2) {
//                                    int tx = nx + dx[t];
//                                    if (0 <= tx && tx < 5) {
//                                        if (v[tx][ny] == 'P') {
//                                            return true;
//                                        }
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//    return false;
//}