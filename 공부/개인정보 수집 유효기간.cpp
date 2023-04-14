#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> term;
    stringstream ss;
    ss.str(today);
    int t_year = 0;
    int t_month = 0;
    int t_day = 0;
    char dot = 0;
    ss >> t_year >> dot >>  t_month >> dot>> t_day;

    for (string s : terms) {
        stringstream ss;
        char t;
        int m;
        ss.str(s);
        ss >> t >> m;
        term.emplace(t, m);
    }

    for (int i = 0; i < privacies.size(); ++i)
    {
        stringstream ss;
        char p_term;
        int p_year = 0;
        int p_month = 0;
        int p_day = 0;

        ss.str(privacies[i]);
        ss >> p_year >> dot>>  p_month >> dot>> p_day >> p_term;
        if (t_year - p_year) p_month -= (12* (t_year - p_year));
        if (t_month - p_month > term[p_term])
        {
            answer.push_back(i + 1);
        }
        else if (t_month - p_month == term[p_term])
        {
            if (t_day >= p_day) answer.push_back(i + 1);
        }
    }
    return answer;
}

int main()
{
    for (int n : solution("2022.05.19",{"A 6", "B 12", "C 3"}, { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" })) {
        cout << n << " ";
    }
}

//auto range = privates.equal_range(term);
//for (auto it = range.first; it != range.second; ++it) {
//    string p_term = it->first;
//    int p_year = 0;
//    int p_month = 0;
//    int p_day = 0;
//    ss.str(it->second);
//    ss>>p_year >> p_month>>p_day;
//    if (t_year - p_year) p_month -= 12;
//    if (t_month - p_month > m)
//    {
//        answer.push_back()
//    }
//}
