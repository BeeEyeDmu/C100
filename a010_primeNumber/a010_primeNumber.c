#include <stdio.h>

int main()
{
    int index;
    int primes = 0;

    for (int i = 2; i < 1000; i++) {
        for (index = 2; index < i; index++) {
            if (i % index == 0)
                break;
        }
        if (index == i) { // i�� �Ҽ����
            primes++;
            printf("%4d%c", i, primes % 15 == 0 ? '\n' : ' ');
        }
    }
    printf("\n2���� 1000������ �Ҽ��� ����: %d��", primes);
}