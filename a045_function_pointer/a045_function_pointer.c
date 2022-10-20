#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

void hello()
{
    printf("Hello\n");
}

int main()
{
    int (*ptr)(int, int) = add;
    void (*fptr)() = hello;

    printf("%d\n", ptr(10, 20));
    fptr();
}