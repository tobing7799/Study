#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
	for (auto v : queries) {
		int size = answer.size();
		vector<int> temp(arr.begin()+v[0], arr.begin()+v[1]+1);
		sort(temp.begin(), temp.end());
		for (int n : temp) {
			if (v[2] < n)
			{
				answer.push_back(n);
				break;
			}
		}
		if (size == answer.size()) answer.push_back(-1);
	}
    return answer;
}

int main()
{
    for (int n : solution({ 0,1,2,4,3 }, { {0,4,2},{0,3,2},{0,2,2} })) {
		cout << n << " ";
    }
}