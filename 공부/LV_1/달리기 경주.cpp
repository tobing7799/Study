#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<int, string> ranks;
    map<string, int> names;
    for (int i = 0; i < players.size(); i++) {
        ranks[i] = players[i]; // 등수와 이름을 map에 저장
        names[players[i]] = i;
    }

    for (string call : callings) {
        int num = names[call];
        string str_p = ranks[num];
        string str_prev = ranks[num-1];
        names[str_p] = num - 1;
        names[str_prev] = num;
        ranks[num] = str_prev;
        ranks[num - 1] = str_p;
    }
    for (auto [num,s] : ranks) {
        answer.emplace_back(s);
    }
    return answer;
}

int main()
{
    for (string s : solution({ "mumu","soe","poe","kai","mine" }, { "kai","kai","mine","mine" })) {
        cout << s << " ";
    }
}

//vector<string> solution(vector<string> players, vector<string> callings) {
//    vector<string> answer;
//    for (string calling : callings) {
//        auto it = find(players.begin(), players.end(), calling);
//        swap(*it, *(it - 1));
//    }
//    return answer = players;
//}


//vector<string> solution(vector<string> players, vector<string> callings) {
//    vector<string> answer;
//    sort(callings.begin(), callings.end());
//    while (callings.size()) {
//        string calling = callings[0];
//        auto it = find(players.begin(), players.end(), calling);
//        int cnt = count(callings.begin(), callings.end(), calling);
//        callings.erase(callings.begin(), callings.begin() + cnt);
//        for (int i = 0; i < cnt; ++i)
//        {
//            swap(*it, *(it - 1));
//            it--;
//        }
//    }
//    return answer = players;
//}

//vector<string> solution(vector<string> players, vector<string> callings) {
//    vector<string> answer;
//    vector<pair<string, int>> calls;
//    sort(callings.begin(), callings.end());
//    while (callings.size()) {
//        string calling = callings[0];
//        int cnt = count(callings.begin(), callings.end(), calling);
//        callings.erase(callings.begin(), callings.begin() + cnt);
//        calls.push_back(make_pair(calling, cnt));
//    }
//    for (auto call : calls) {
//        auto it = find(players.begin(), players.end(), call.first);
//        string s = *it;
//        auto p = it - 1;
//        players.erase(it);
//        players.insert(p - call.second + 1, s);
//    }
//    return answer = players;
//}
