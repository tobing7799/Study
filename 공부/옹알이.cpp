#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<string.h>

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;
    int aya = 0;
    int ye = 0;
    int woo = 0;
    int ma = 0;
    int length = 0;
    for (int i = 0; i< babbling_len; ++i)
    {
        for (int j = 0; j < strlen(babbling[i]); ++j)
        {
            switch (babbling[i][j]) {
            case 'a':
                if (babbling[i][j + 1] == 'y' && babbling[i][j + 2] == 'a')
                {
                    aya++;
                }
                j += 2;
                break;
            case 'y':
                if (babbling[i][j + 1] == 'e')
                {
                    ye++;
                }
                j += 1;
                break;
            case 'w':
                if (babbling[i][j + 1] == 'o' && babbling[i][j + 2] == 'o')
                {
                    woo++;
                }
                j += 2;
                break;
            case 'm':
                if (babbling[i][j + 1] == 'a')
                {
                    ma++;
                }
                j += 1;
                break;
            default:
                break;
            }
        }
        length = strlen(babbling[i]);
        if (aya)
        {
            length -= 3;
            aya = 0;
        }
        if (ye)
        {
            length -= 2;
            ye = 0;
        }
        if (woo)
        {
            length -= 3;
            woo = 0;
        }
        if (ma)
        {
            length -= 2;
            ma = 0;
        }
        if (length == 0)
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    const char* babbling[4] = { "aya","woo","ayes","wowoma"};

    printf("%d",solution(babbling, 4));

}