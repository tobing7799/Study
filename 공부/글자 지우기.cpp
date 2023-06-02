#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    for (int n : indices) {
        my_string[n]='.';
    }
    for(int i=0; i<indices.size(); ++i)
        my_string.erase(my_string.begin()+my_string.find('.'));
    return answer = my_string;
}

int main()
{
    cout << solution("apporoograpemmemprs", { 1, 16, 6, 15, 0, 10, 11, 3 });
}