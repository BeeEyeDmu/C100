#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n;
    printf("홀수 n을 입력하세요 : ");
    scanf("%d", &n);

    // 위쪽 줄
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < i; j++) // 0
            printf(" %c", '0');
        printf(" %c", 'X'); // X
        for (int j = 0; j < n - 2 * (i + 1); j++)
            printf(" %c", '0');
        printf(" %c", 'X'); // X
        for (int j = 0; j < i; j++)  // 0
            printf(" %c", '0');
        printf("\n");
    }

    // 중간줄
    for (int j = 0; j < n / 2; j++)
        printf(" %c", '0');
    printf(" %c", 'X');
    for (int j = 0; j < n / 2; j++)
        printf(" %c", '0');
    printf("\n");

    // 아래쪽 줄
    for (int i = n / 2 - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) // 0
            printf(" %c", '0');
        printf(" %c", 'X'); // X
        for (int j = 0; j < n - 2 * (i + 1); j++)
            printf(" %c", '0');
        printf(" %c", 'X'); // X
        for (int j = 0; j < i; j++)  // 0
            printf(" %c", '0');
        printf("\n");
    }
}