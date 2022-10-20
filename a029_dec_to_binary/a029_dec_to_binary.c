#define _CRT_SECURE_NO_WARNINGS
#define SIZE    32
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int checkOverflow(char buffer[])
{
    char intmax[11];

    _itoa(INT_MAX, intmax, 10);
    if (strlen(buffer) > strlen(intmax))
        return 1;
    else if (strlen(buffer) == strlen(intmax)) {
        for (int i = 0; i < 11; i++)
            if (buffer[i] > intmax[i])
                return 1;
    }
    return 0;
}

void array_d2b(int n)
{
    int arr[SIZE] = { 0 };
    int i, length = 0; // 배열의 길이

    for (i = 0; n > 0; i++) {
        arr[i] = n % 2;
        n /= 2;
        length++;
    }
    length--;

    while (length >= 0) { // 배열을 뒤에서부터 출력
        printf("%d", arr[length]);
        length--;
    }
}

void recursive_d2b(int n)
{
    if (n >= 2)
        recursive_d2b(n / 2);
    printf("%d", n % 2);
}

int main()
{
    int n;
    char number[11] = { 0 };  // 10자리 + '\0'

    printf("10진수 정수를 입력하세요: ");
    scanf("%s", number);

    if (checkOverflow(number) == 1) {
        printf("입력한 숫자가 정수의 범위를 넘어섭니다.\n");
        exit(0);
    }

    n = atoi(number);

    printf("\n10진수 %d의 2진수는 : ", n);
    array_d2b(n);

    printf("\n10진수 %d의 2진수는 : ", n);
    recursive_d2b(n);
}