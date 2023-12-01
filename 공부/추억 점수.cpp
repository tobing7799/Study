#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer(photo.size());
    map<string, int> m;
    for (int i = 0; i < name.size(); ++i) {
        m[name[i]] = yearning[i];
    }

    for (int i = 0; i < photo.size(); ++i) {
        for (string s : photo[i]) {
            answer[i] += m[s];
        }
    }
    return answer;
}

int main()
{
    for (int n : solution({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 }, { {"may", "kein", "kain", "radi"},{"may", "kein", "brin", "deny"},{"kon", "kain", "may", "coni"} })) {
        cout << n << ' ';
    }
}