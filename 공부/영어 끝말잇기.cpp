#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, int> um;
    int count = 0;
    char prev=0;

    for (string s : words) {
        if (!um.empty() && (um.find(s) != um.end() || prev != *s.begin())) {
            answer.push_back((count % n) + 1);
            answer.push_back((count / n) + 1);
            break;
        }
        else {
            um.insert({ s,0 });
            prev = s.back();
            count++;
        }
    }
    if (answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}

int main()
{
    for (int n : solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" })) {
        cout << n << ' ';
    }
}