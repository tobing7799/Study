#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    for (int i = 0; i < arr.size(); ) {
        if (stk.empty()) { stk.push_back(arr[i]); i++; }
        else if (stk.back() < arr[i]) { stk.push_back(arr[i]); i++; }
        else if (stk.back() >= arr[i]) { stk.erase(stk.end() - 1);}

        for (int n : stk) {
            cout << n << " ";
        }
        cout << endl;
    }
    return stk;
}

int main()
{
    for (int n : solution({ 1,4,2,5,3 })) {
        cout << n << " ";
    }
}