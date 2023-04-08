#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";

    transform(my_string.begin(), my_string.end(), my_string.begin(), [](char elem) {
        return tolower(elem);});
    sort(my_string.begin(), my_string.end());
    answer = my_string;

    return answer;
}

int main()
{
    string input = "Bcad";
    cout << solution(input);
}