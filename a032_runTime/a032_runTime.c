#include <stdio.h>
#include <time.h>

int main()
{
    double start, end;

    // ���� �ð�
    start = (double)clock() / CLOCKS_PER_SEC;

    int sum = 0;
    for (int i = 0; i < 10000000; i++) {
        sum++;
    }

    // �� �ð�
    end = (double)clock() / CLOCKS_PER_SEC;
    printf("sum = %d, ���� �ð� = %lf��\n", sum, end - start);
}