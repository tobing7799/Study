#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

void MakeCombination(unordered_map<string, vector<int>>& infoMap, const vector<string>& infoTokens, int score) {
    for (int i = 0; i < (1 << 4); i++) {
        string key = "";
        for (int j = 0; j < 4; j++) {
            if (i & (1 << j))  key += "-";
            else key += infoTokens[j];
            key += " ";
        }
        infoMap[key].push_back(score);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    unordered_map<string, vector<int>> infoMap;

    for (const string& inf : info) {
        stringstream ss(inf);
        vector<string> infoTokens(5);
        for (int i = 0; i < 5; i++) {
            ss >> infoTokens[i];
        }
        int score = stoi(infoTokens[4]);
        infoTokens.pop_back();

        MakeCombination(infoMap, infoTokens, score);
    }

    for (auto& entry : infoMap) {
        sort(entry.second.begin(), entry.second.end());
    }

    vector<int> answer;

    for (const string& q : query) {
        stringstream ss(q);
        string lang, pos, career, food, scoreStr;
        ss >> lang >> scoreStr >> pos >> scoreStr >> career >> scoreStr >> food >> scoreStr;
        int score = stoi(scoreStr);

        string key = lang + " " + pos + " " + career + " " + food + " ";

        if (infoMap.find(key) != infoMap.end())
        {
            const vector<int>& scores = infoMap[key];
            auto it = lower_bound(scores.begin(), scores.end(), score);
            answer.push_back(scores.end() - it);
        }
        else
        {
            answer.push_back(0);
        }
    }
    return answer;
}

int main()
{
    vector<string>info{ {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" } };
    vector<string>query{ {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" } };

    for (int num : solution(info, query))
    {
        cout << num << endl;
    }
}