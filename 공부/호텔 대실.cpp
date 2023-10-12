#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    sort(book_time.begin(), book_time.end(), [](vector<string> v1, vector<string>v2) { return v1[0] < v2[0]; });

    vector <vector<int>> room(1,vector<int>(2));

    for(vector<string> v : book_time) {
        
        stringstream ss{v[0]+":"+ v[1]};
        int phour, pmin, nhour,nmin;
        char c;
        ss >> phour >> c >> pmin >> c >> nhour >> c >> nmin;

        for (int i = 0; i < room.size(); ++i) {
            if (room[i][1] <= (phour * 60 + pmin)) {
                room[i][0] = (phour * 60 + pmin);
                room[i][1] = (nhour * 60 + nmin + 10);
                break;
            }
            else if (room[i][0] >= (nhour * 60 + nmin + 10)){
                break;
            }
            else if (i == room.size() - 1) {
                room.push_back(vector<int>{phour * 60 + pmin, nhour * 60 + nmin + 10});
                break;
            }
        }
    }
    return answer = room.size();
}

int main()
{
    cout << solution({ {"08:00", "08:30" },{"08:00", "13:00" },{"12:30", "13:30"} });
}