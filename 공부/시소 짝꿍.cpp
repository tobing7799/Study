#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
	vector<int> total(4001);
	vector<int> original(1001);

	for (int n : weights) {
		answer += total[n * 2];
		answer += total[n * 3];
		answer += total[n * 4];

		if (original[n] > 0) answer -= original[n] * 2;

		original[n]++;
		total[n * 2]++;
		total[n * 3]++;
		total[n * 4]++;
	}
    return answer;
}

int main()
{
    cout << solution({ 100,180,360,100,270 });
}