#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    vector<string> number{"zero","one", "two","three","four","five","six","seven","eight","nine"};
    for (int i=0; i<number.size(); ++i)
    {
        int temp;
        while ((temp = numbers.find(number[i])) != std::string::npos) {
            numbers.replace(temp,number[i].size(), to_string(i));
        }
    }
    return answer = stoll(numbers);
}

int main()
{
    cout << solution("onetwothreefourfivesixseveneightnine");
}

/*
이 방법이 위 방법에 비해 0.01초씩 빠름.
long long solution(string numbers) {
    string answer = "";
    while (numbers != "")
    {
        switch (numbers[0]) {
        case 'z':
            answer += "0";
            numbers.erase(0, 4);
            break;
        case 'o':
            answer += "1";
            numbers.erase(0, 3);
            break;
        case 't':
            if (numbers[1]=='w')
            {
                answer += "2";
                numbers.erase(0, 3);
            }
            else
            {
                answer += "3";
                numbers.erase(0, 5);
            }
            break;
        case 'f':
            if (numbers[1] == 'o')
            {
                answer += "4";
                numbers.erase(0, 4);
            }
            else
            {
                answer += "5";
                numbers.erase(0, 4);
            }
            break;
        case 's':
            if (numbers[1] == 'i')
            {
                answer += "6";
                numbers.erase(0, 3);
            }
            else
            {
                answer += "7";
                numbers.erase(0, 5);
            }
            break;
        case 'e':
            answer += "8";
            numbers.erase(0, 5);
            break;
        case 'n':
            answer += "9";
            numbers.erase(0, 4);
            break;
        }
    }
    return stol(answer);
}
*/