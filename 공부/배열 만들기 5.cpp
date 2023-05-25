#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    string temp;
    for (string str : intStrs) {
        temp = str.substr(s, l);
        if (stoi(temp) > k)
        {
            answer.push_back(stoi(temp));
        }
    }
    return answer;
}

int main()
{
    for (int n : solution({ "0123456789","9876543210","9999999999999" }, 50000, 5, 5)) {
        cout << n << " ";
    }
}