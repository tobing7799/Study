#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";

    int month[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
    string week[] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
    int totalday = 0;

    for (int i = 1; i < a; ++i)
    {
        totalday += month[i];
    }
    totalday += b - 1;

    answer = week[totalday % 7];
    return answer;
}

int main()
{
    cout << solution(5, 24);
}