#include <stdio.h>

enum Size { Short, Tall, Grande, Venti };
char sizeName[][7] = { "Short", "Tall", "Grande", "Venti" };
int priceAmericano[] = { 3800, 4100, 4600, 5100 };
int priceCapucciono[] = { 4600, 5900, 6400, 6900 };

int main()
{
    printf("커피 가격표(아메리카노)\n");
    for (int i = Short; i < Venti; i++)
        printf("%10s : %5d\n", sizeName[i], priceAmericano[i]);

    printf("커피 가격표(카푸치노)\n");
    for (int i = Short; i <= Venti; i++)
        printf("%10s : %5d\n", sizeName[i], priceCapucciono[i]);
}