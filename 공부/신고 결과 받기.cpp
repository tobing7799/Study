#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include<algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    //multimap<string, string> list;
   // map<pair<string,string>, int>banlist;

    map<string , vector<string>> banlist;
    map<string,int>bancount;

    //for (string s : report) {
    //    stringstream ss(s);
    //    string first, second;
    //    ss >> first;
    //    ss >> second;
    //    banlist[second]++;
    //    list.insert(make_pair(first,second));
    //}
    //for (string s : id_list) {
    //    int count = 0;
    //    auto range = list.equal_range(s);
    //    for (auto i = range.first; i != range.second; ++i) {
    //        if (banlist[i->second] >= k) count++;
    //    }
    //    answer.push_back(count);
    //}
    // 
    for (string s : report) {
        stringstream ss(s);
        string first, second;
        ss >> first >> second;
        if (banlist[first].end() == find(banlist[first].begin(), banlist[first].end(), second))
        {
            bancount[second]++;
            banlist[first].push_back(second);
        }
    }

    for (string s : id_list) {
        int num = 0;
        for (string ss : banlist[s])
        {
            if (bancount[ss] >= k) num++;
            //answer.push_back(count_if(banlist[s].begin(), banlist[s].end(), [&](const string& s) { return bancount[s] >= k; }));
        }
        answer.push_back(num);
    }
    return answer;
}

int main()
{
    for (int n : solution({ "muzi", "frodo", "apeach", "neo" }, { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" }, 2)) {
        cout << n << " ";
    }
}