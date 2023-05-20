#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int a, int b, int c, int d) {
    int dice[4] = { a, b, c, d };
    sort(dice, dice + 4);

    if (dice[0] == dice[3]) {
        return dice[0] * 1111;
    }

    if (dice[0] == dice[2] || dice[1] == dice[3]) {
        int p = dice[0] == dice[2] ? dice[0] : dice[1];
        int q = dice[0] == dice[2] ? dice[3] : dice[0];
        return (10 * p + q) * (10 * p + q);
    }

    if ((dice[0] == dice[1] && dice[2] == dice[3]) || (dice[0] == dice[2] && dice[1] == dice[3])) {
        int p = dice[0] == dice[1] ? dice[0] : dice[2];
        int q = dice[0] == dice[1] ? dice[2] : dice[0];
        return (p + q) * std::abs(p - q);
    }

    if (dice[0] == dice[1] || dice[1] == dice[2] || dice[2] == dice[3]) {
        int p = dice[0] == dice[1] ? dice[2]*dice[3] : (dice[1] == dice[2] ? dice[0]*dice[3] : dice[0]*dice[1]);
        return p;
    }
    return dice[0];
}


int main()
{
    cout << solution(2,5,2,6);
}