#include <stdio.h>

enum Size { Short, Tall, Grande, Venti };
char sizeName[][7] = { "Short", "Tall", "Grande", "Venti" };
int priceAmericano[] = { 3800, 4100, 4600, 5100 };
int priceCapucciono[] = { 4600, 5900, 6400, 6900 };

int main()
{
    printf("Ŀ�� ����ǥ(�Ƹ޸�ī��)\n");
    for (int i = Short; i < Venti; i++)
        printf("%10s : %5d\n", sizeName[i], priceAmericano[i]);

    printf("Ŀ�� ����ǥ(īǪġ��)\n");
    for (int i = Short; i <= Venti; i++)
        printf("%10s : %5d\n", sizeName[i], priceCapucciono[i]);
}