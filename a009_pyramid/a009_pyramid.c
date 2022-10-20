#include <stdio.h>

int main()
{
    // (1)
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
    printf("\n");

    // (2)
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("*");
        printf("\n");
    }
    printf("\n");

    // (3)
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
    printf("\n");

    // (4)
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5 - i; j++)
            printf(" ");
        for (int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
    printf("\n");

    // (5)
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5 - i; j++)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("*");
        printf("\n");
    }
    printf("\n");

    // (6)
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= 5 - i; j++)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("*");
        printf("\n");
    }
}