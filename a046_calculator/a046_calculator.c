#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    return a / b;
}

int main()
{
    float a, b;
    int choice;
    float (*funcptr[4])(float, float)
        = { add, subtract, multiply, divide };

    printf("Enter two numbers : ");
    scanf("%f %f", &a, &b);
    printf("Enter choice[0:add, 1:subtract, 2:multiply, 3:divide] : ");
    scanf("%d", &choice);

    printf("result = %f\n", funcptr[choice](a, b));
}