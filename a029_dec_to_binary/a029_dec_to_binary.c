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
    int i, length = 0; // �迭�� ����

    for (i = 0; n > 0; i++) {
        arr[i] = n % 2;
        n /= 2;
        length++;
    }
    length--;

    while (length >= 0) { // �迭�� �ڿ������� ���
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
    char number[11] = { 0 };  // 10�ڸ� + '\0'

    printf("10���� ������ �Է��ϼ���: ");
    scanf("%s", number);

    if (checkOverflow(number) == 1) {
        printf("�Է��� ���ڰ� ������ ������ �Ѿ�ϴ�.\n");
        exit(0);
    }

    n = atoi(number);

    printf("\n10���� %d�� 2������ : ", n);
    array_d2b(n);

    printf("\n10���� %d�� 2������ : ", n);
    recursive_d2b(n);
}