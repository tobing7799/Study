#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<string.h>

// babbling_len�� �迭 babbling�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
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