#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> alldiscount;

    for (int i = 0; i < want.size(); ++i) {
        alldiscount[want[i]] += number[i];
    }

    int cnt = 0;
    int continuous = 0;

    for (string s : discount) {
        cnt++;
        continuous++;
        if (alldiscount.find(s) != alldiscount.end()) alldiscount[s]--;

        bool can = true;
        for (auto pair : alldiscount) {
            if (pair.second > 0) {
                can = false;
                break;
            }
        }
        if (continuous == 10 && can) answer++;
        if (continuous >= 10) {
            if(alldiscount.find(discount[cnt - 10]) != alldiscount.end()) alldiscount[discount[cnt - 10]]++;
            continuous--;
        }
    }
    return answer;
}

int main()
{
    cout << solution({ "banana", "apple", "rice", "pork", "pot" }, { 3, 2, 2, 2, 1 }, { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" });
}