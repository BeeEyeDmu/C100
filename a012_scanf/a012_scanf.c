#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int i, a, b, c;
    int day, month, year;
    char s[100];

    int x = scanf("%d %c %d", &a, &i, &b);  // 12 + 34
    printf("scanf�� ���ϰ� = %d\n", x);
    printf("(1) %d %c %d\n", a, i, b);
    c = getchar();            // '\n'�� �д´�

    scanf("%[0-9]", s);      // 1234abc567
    printf("(2) %s\n", s);

    scanf("%[^\n]", s);      // '\n' �ձ��� �д´�. ^�� up-to�� �ǹ�
    printf("(3) %s\n", s);

    scanf("%*d%s", &s);      // 123abc �Ǵ� 123 abc
    printf("(4) %s\n", s);

    scanf("%d%*c%d%*c%d", &day, &month, &year);    // 30/08/2022
    printf("(5) %d %d %d\n", year, month, day);

    scanf("%d%*s%d%*s%d%*s", &year, &month, &day);  // 2022�� 8�� 30��
    printf("(6) %d %d %d\n", year, month, day);

    scanf("%5d%[^\n]", &i, s);  // 1234567
    printf("(7) %d\n", i);

    scanf("%5d%2d", &a, &b);    // 1234567
    printf("(8) %d %d\n", a, b);
}