#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss{ s };

    int max = INT_MIN;
    int min = INT_MAX;
    int num = 0;

    while (ss >> num) {
        if (max < num) max = num;
        if (min > num) min = num;
    }
    return answer = to_string(min) + " " + to_string(max);
}

int main()
{
    cout << solution("1 2 3 4") << endl;
}