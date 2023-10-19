#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<vector<int>> mine;

    int max = 0;
    int diamond = 0;
    int iron = 0;
    int stone = 0;
    int pick = 0;

    for (int n : picks) {
        max+= (n * 5);
    }

    max = max > minerals.size() ? minerals.size() : max;

    for (int i=0; i<max; ++i) {
        if (diamond + iron + stone == 5) {
            mine.push_back(vector<int>{diamond, iron, stone});
            diamond = 0, iron = 0, stone = 0;
        }
        if (minerals[i] == "diamond") diamond++;
        else if ( minerals[i] == "iron") iron++;
        else stone++;
    }
    mine.push_back(vector<int>{diamond, iron, stone});

    sort(mine.begin(), mine.end(), [](const vector<int> a, const vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
            if (a[1] == b[1]) return a[2] > b[2];
        }
        return a[0] > b[0];});

    for (vector<int> v : mine) {
        while (picks[pick] == 0) {
            pick++;
        }
        int n = pick;
        picks[pick]--;
        diamond = v[0] > 0 ? n > 0 ? pow(5, n) * v[0] : 1 * v[0] : 0;
        iron = v[1] > 0 ? n > 1 ? 5 * v[1] : 1 * v[1] : 0;
        stone = v[2] * 1;
        answer += (diamond + iron + stone);
        diamond = 0, iron = 0, stone = 0;
    }
    return answer;
}

int main()
{
    cout << solution({ 0,1,1 }, {"diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" });
}

//5���� ���, �� ������ ������ �����ϰ�, ���� ���� ����� ���� ������ ���� ������ ���̾Ʒ� ĳ����.
//vector<vevctor<int>> total? ����