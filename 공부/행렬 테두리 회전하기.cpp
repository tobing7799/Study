#include <string>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
	vector<int>number(rows * columns);
	iota(number.begin(), number.end(), 1);

	for (vector<int> v : queries) {
		int x1 = v[1]-1, y1 = v[0]-1, x2 = v[3], y2 = v[2];
		int min = rows * columns;

		int change = number[y1 * columns + x1];
		number[y1 * columns + x1] = number[(y1 + 1) * columns + x1];
		if (change < min) min = change;
		while (++x1 != x2) {
			swap(number[y1 * columns + x1], change);
			if (change < min) min = change;
		}
		--x1;
		while (++y1 != y2) {
			swap(number[y1 * columns + x1], change);
			if (change < min) min = change;
		}
		--y1;
		--x1;
		while (x1 != v[1] - 1) {
			swap(number[y1 * columns + x1--], change);
			if (change < min) min = change;
		}
		while (y1 != v[0]-1) {
			swap(number[y1-- * columns + x1], change);
			if (change < min) min = change;
		}
		answer.push_back(min);
	}
    return answer;
}

int main()
{
	for (int n : solution(100, 97, { {1,1,100,97} })) {
		cout << n << " ";
	}
}