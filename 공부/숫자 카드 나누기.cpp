#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool Check(vector<int>arr, int num) {
	for (int n : arr) {
        if (n % num == 0) return false;
	}
    return true;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int numA = arrayA[0];
    int numB = arrayB[0];
    for (int i = 1; i < arrayA.size(); ++i) {
        numA = gcd(numA, arrayA[i]);
    }
    for (int i = 1; i < arrayB.size(); ++i) {
        numB = gcd(numB, arrayB[i]);
    }
    if (numA == numB) return 0;
    if(!(Check(arrayA, numB)) || numB<2) numB =0;
    if(!(Check(arrayB, numA)) || numA<2) numA =0;
    return answer = max(numA,numB);
}

int main()
{
    cout << solution({ 10, 20 }, { 5, 17 });
}