#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool Dfs(vector<vector<string>>& tickets, vector<string>&answer, vector<bool>&visited, string node, int cnt) {
    answer.push_back(node);

    if (cnt == tickets.size()) return true;

    for (int i = 0; i < tickets.size(); ++i) {
        if (!visited[i] && tickets[i][0] == node) {
            visited[i] = true;
            if (Dfs(tickets, answer, visited, tickets[i][1], cnt + 1)) return true;
            else visited[i] = false;
        }
    }
    answer.pop_back();
    return false;
}



vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size(),false);
    sort(tickets.begin(), tickets.end(), [](vector<string>& a, vector<string>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0]; });

    Dfs(tickets, answer, visited, "ICN", 0);

    return answer;
}

int main()
{
    for (string s : solution({ {"ICN", "JFK"},{ "ICN", "AAD"}, {"JFK", "ICN"} })) {
        cout << s << " ";
    }
}