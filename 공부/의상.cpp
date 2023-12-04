#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int>map;
    for (int i = 0; i < clothes.size(); ++i) {
        map[clothes[i][clothes[i].size() - 1]]++;
    }

    for (pair<string, int> p : map) {
        answer = answer * (p.second + 1);
    }
    return answer-1;
}

int main()
{
    cout << solution({ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} });
}