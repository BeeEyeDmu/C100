#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#define MAXVAL  100

int stack[MAXVAL];  // stack
int sp = 0;          // stack pointer

void push(int v)
{
    if (sp < MAXVAL)
        stack[sp++] = v;
    else
        printf("stack full\n");
}

int pop()
{
    if (sp > 0)
        return stack[--sp];
    else {
        printf("error: stack empty\n");
        return 0;
    }
}

void printStack()
{
    printf("Stack : ");
    for (int i = 0; i < sp; i++)
        printf("%8d", stack[i]);
    printf("\n");
}

int main()
{
    int c, v;
    while (1)
    {
        printf("Operatrion: i(insert), d(Delete), q(quit) : ");
        c = _getche();
        printf("\n");

        switch (c) {
        case 'i':
            printf("Enter a number : ");
            scanf("%d", &v);
            push(v);
            break;
        case 'd':
            printf("%d removed\n", pop());
            break;
        case 'q':
            return 0;
        }
        printStack();
    }
}