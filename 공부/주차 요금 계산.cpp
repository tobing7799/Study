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
        if ( p == table.end()) {// ���� ��� ����
            table.insert(make_pair(number, timetominute));
        }
        else {//�ִ� ��� ����
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

// ���� �ִ� 1000��, �̿����� ���� �˻��ϴ� ����� ��θ� �ȵ�
// unordered map�� ����ϴ°� ���� �� ����. O(1)�� �˻� ����� ���� �ֱ� ����.
// unordered_map<int,string>���� ������ȣ�� key������ �δ°� ���ƺ���. �ֳ��ϸ� ���� �ð��� ���� ������ȣ�� ���� ����.
// ����� ����� �������� ����� ���� �����̳ʵ� �ʿ��غ���.
// �̰��� unordered_map�� find�� ã�� iter�� �ް� insert�� ���ִ� �۾����� ������ �ʹ� ���� ������ �����ϰ� ������ �����ϸ� ���� �� ����.
//