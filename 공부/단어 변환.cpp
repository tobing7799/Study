#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int Different(string& str1, string& str2)
{
    int count = 0;
    for (int i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i]) count++;
    }
    return count;
}

int BFS(string begin, string target, vector<string>& words, vector<bool>& visited)
{
    queue<pair<string,int>> q;
    q.push(make_pair(begin,0));
    
    string node;
    
    while (!q.empty()) {
        node = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (Different(node, target) == 0) return cnt;

        for (int i = 0; i < words.size(); ++i) {
            if (visited[i]) continue;

            if (Different(node, words[i]) == 1) {
                q.push(make_pair(words[i], cnt+1));
                visited[i] = true;
            }
        }
    }

    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    if (find(words.begin(), words.end(), target) == words.end()) return 0;

    vector<bool> visited(words.size());
    int result = BFS(begin, target, words, visited);

    return answer = result ? result : 0;
}

int main()
{
    cout << solution("hit", "cog", { "cog", "log", "lot", "dog", "dot", "hot" });
}