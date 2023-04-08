#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer{0,0};
    int x = (board[0]-1)/2;
    int y = (board[1]-1)/2;

    for (string s : keyinput)
    {
        if (s == "right" && answer[0] < x) answer[0]++;
        else if (s == "left" && answer[0] > -x) answer[0]--;
        else if (s == "up" && answer[1] < y ) answer[1]++;
        else if (s == "down" && answer[1] > -y) answer[1]--;

    }
    return answer;
}

int main()
{
    for (int n : solution({ "left", "right", "up", "right", "right" }, { 11,11 }))
    {
        cout << n << " ";
    }
}