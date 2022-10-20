#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXOP   100
#define MAXVAL  100
#define NUMBER  '0'

float stack[MAXVAL];  // stack
int sp = 0;            // stack pointer

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')  // 숫자 아님
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getchar())) // 정수부분 읽기
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getchar())) // 소수부분 읽기
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetc(c, stdin);
    return NUMBER;
}

void push(float f)
{
    if (sp < MAXVAL)
        stack[sp++] = f;
    else
        printf("Stack full\n");
}

float pop()
{
    if (sp > 0)
        return stack[--sp];
    else {
        printf("error: stack empty\n");
        return 0;
    }
}

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            push(-(pop() - pop()));
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            push(1 / (pop() / pop()));
            break;
        case '\n':
            printf("%.8g\n", pop());
            break;
        default:
            printf("Unknown %s\n", s);
            break;
        }
    }
}