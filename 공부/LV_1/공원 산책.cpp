#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x = 0;
    int y = 0;
    int xMax = park[0].size()-1;
    int yMax = park.size()-1;
    for (string s : park) {
        x = s.find('S');
        if (x != string::npos) break;
        y++;
    }

    for (string s : routes) {
     istringstream str(s);
     char c = 0;
     int num = 0;
     int xTemp = x;
     int yTemp = y;
     str >> c >> num;
     while (num) {
         switch (c) {
         case 'E':
             xTemp++;
             break;
         case 'S':
             yTemp++;
             break;
         case 'W':
             xTemp--;
             break;
         case 'N':
             yTemp--;
             break;
         }
         if (xTemp > xMax || yTemp > yMax || xTemp < 0 || yTemp < 0)
         {
             break;
         }
         if (park[yTemp][xTemp] == 'X') break;
         num--;
         if (num == 0)
         {
             x = xTemp;
             y = yTemp;
         }
     }
    }
    answer.push_back(y);
    answer.push_back(x);
    return answer;
}

int main()
{
    for (int n : solution({ "OSO","OOO","OXO","OOO"}, {"E 2", "S 3", "W 1"})) {
        cout << n << " ";
    }
}