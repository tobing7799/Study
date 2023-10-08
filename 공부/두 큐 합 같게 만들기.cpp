#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
	int answer = 0;
	long long q1sum = accumulate(queue1.begin(), queue1.end(), 0);
	long long q2sum = accumulate(queue2.begin(), queue2.end(), 0);
	int index1 = 0;
	int index2 = 0;
	int totalsize = queue1.size() + queue2.size();
	while (answer <= totalsize * 4) {
		if (q1sum > q2sum) {
			q1sum -= queue1[index1];
			q2sum += queue1[index1];
			queue2.push_back(queue1[index1++]);
		}
		else if (q1sum < q2sum) {
			q1sum += queue2[index2];
			q2sum -= queue2[index2];
			queue1.push_back(queue2[index2++]);
		}
		else break;
		answer++;
	}
	if (answer > totalsize * 4) answer = -1;
	return answer;
}

int main()
{
	//cout << solution({ 2, 3, 2 }, { 1, 1, 1 });
	//cout << solution({ 3, 2, 7, 2 }, { 4, 6, 5, 1 });
    cout << solution({ 1,1 }, { 1,5 });
}

//int solution(vector<int> queue1, vector<int> queue2) {
//    int answer = 0;
//    while (1) {
//        long long q1sum = accumulate(queue1.begin(), queue1.end(), 0);
//        long long q2sum = accumulate(queue2.begin(), queue2.end(), 0);
//        long long diff = q1sum > q2sum ? q1sum - (q1sum + q2sum) / 2 : q2sum - (q1sum + q2sum) / 2;
//        if (q1sum > q2sum) {
//            while (diff > 0 && answer <= queue1.size() + queue2.size()) {
//                long long temp = *queue1.begin();
//                queue1.erase(queue1.begin());
//                queue2.push_back(temp);
//                diff -= temp;
//                answer++;
//            }
//        }
//        else if (q1sum < q2sum) {
//            while (diff > 0 && answer <= queue1.size() + queue2.size()) {
//                long long temp = *queue2.begin();
//                queue2.erase(queue2.begin());
//                queue1.push_back(temp);
//                diff -= temp;
//                answer++;
//            }
//        }
//        else if (q1sum == q2sum) break;
//        if (answer > queue1.size() + queue2.size()) {
//            answer = 0;
//            break;
//        }
//    }
//    if (!answer) answer = -1;
//    return answer;
//}

//int solution(vector<int> queue1, vector<int> queue2) {
//    int answer = -1;
//    vector<int> numbers(queue1.begin(), queue1.end());
//    numbers.insert(numbers.end(), queue2.begin(), queue2.end());
//    long long sum = accumulate(numbers.begin(), numbers.end(), 0);
//    long long half = sum / 2;
//    int index = 0;
//
//    numbers.insert(numbers.end(), numbers.begin(), numbers.end());
//    for (int i = 0; i < numbers.size(); ++i) {
//        sum -= numbers[i];
//        while (sum < half) {
//            sum += numbers[index];
//            index++;
//        }
//        if (sum == half) {
//            if (i < queue1.size() + queue2.size()) {
//                numbers.erase(numbers.begin() + (numbers.size() / 2), numbers.end());
//                numbers.erase(numbers.begin() + index, numbers.begin() + i + 1);
//            }
//            else if (i > queue1.size() + queue2.size()) {
//                numbers.erase(numbers.begin() + i, numbers.end());
//                numbers.erase(numbers.begin(), numbers.begin() + i - queue1.size() + queue2.size() + 1);
//            }
//            if (half == accumulate(numbers.begin(), numbers.end(), 0)) {
//                if (i <= queue1.size() + queue2.size()) answer = index + i - queue1.size() + 1;
//                else answer = i - queue1.size() + queue2.size() + (queue1.size() < index ? index - queue1.size() : 0);
//            }
//            else answer = -1;
//            break;
//        }
//    }
//    return answer;
//}