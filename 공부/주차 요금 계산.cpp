#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<int, int> table;
    map<int, int> result;
    for (string s : records) {
        stringstream ss;
        ss.str(s);
        string time;
        int number;
        int hour, minute, timetominute;

        ss >> time >> number;
        time[2] = ' ';
        ss.str(time);
        ss >> hour >> minute;
        
        timetominute = hour * 60 + minute;

        auto p = table.find(number);
        if ( p == table.end()) {// 없는 경우 입차
            table.insert(make_pair(number, timetominute));
        }
        else {//있는 경우 출차
            int totalminute = timetominute - (*p).second;
            result[number] += totalminute;
            table.erase(p);
        }
    }

    for (auto remain : table) {
        int totalminute = (23 * 60 + 59) - remain.second;
        result[remain.first] += totalminute;
    }

    for (auto m : result) {
        int basictime = m.second - fees[0];
        int fee = 0;
        if (basictime<0) fee = fees[1];
        else fee = (m.second - fees[0]) % fees[2] > 0 ? fees[1] + ((m.second - fees[0]) / fees[2] + 1) * fees[3] : fees[1] + ((m.second - fees[0]) / fees[2]) * fees[3];
        answer.push_back(fee);
    }
    return answer;
}

int main()
{
    for (int n : solution({ 180, 5000, 10, 600 }, { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" })) {
        cout << n << " ";
    }
}

// 차는 최대 1000대, 이에따라 차를 검색하는 비용이 비싸면 안됨
// unordered map을 사용하는게 좋을 것 같음. O(1)의 검색 비용을 갖고 있기 때문.
// unordered_map<int,string>으로 차량번호를 key값으로 두는게 좋아보임. 왜냐하면 같은 시각에 같은 차량번호는 없기 때문.
// 비용을 계산한 최종적인 비용을 담을 컨테이너도 필요해보임.
// 이것은 unordered_map는 find로 찾고 iter를 받고 insert를 해주는 작업으로 과정이 너무 많기 때문에 간단하게 맵으로 관리하면 좋을 것 같음.
//