#include <stdio.h>
#define INT 0
#define FLOAT 1

void sum_of_array(void* p, int length, void* result, int type)
{
    switch (type) {
    case INT:
        for (int i = 0; i < length; i++)
            *(int*)result += *((int*)p + i);
        break;
    case FLOAT:
        for (int i = 0; i < length; i++)
            *(float*)result += *((float*)p + i);
        break;
    }
}

int main()
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    float b[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    int intSum = 0;
    float floatSum = 0;

    sum_of_array(a, 10, &intSum, INT);
    printf("%d\n", intSum);
    sum_of_array(b, 5, &floatSum, FLOAT);
    printf("%f\n", floatSum);
}