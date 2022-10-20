#include <stdio.h>
#include <ctype.h>  
#include <stdlib.h> 
#include <stdbool.h>

double calculate(double x, char op, double y)
{
    switch (op) {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        return 0.0;
    }
}

int main()
{
    char buf[80];
    double result = 0.0;
    char op = '+';

    while (true)
    {
        printf("\n��Ģ����(����� 'q'�� �Է��ϼ���)\n");
        printf("������ �Է��ϼ���. ��) a+b | a-b | a*b | a/b\n ==> ");

        fgets(buf, 80, stdin);
        char* p = buf;
        double value[2] = { 0.0 };
        int index = 0;

        while (*p != '\n') {
            if (*p == 'q')
                return 0;
            if (isdigit(*p)) {
                float v = strtof(p, &p);
                value[index++] = v;
            }
            else if (*p == '+')
                op = '+', p++;
            else if (*p == '-')
                op = '-', p++;
            else if (*p == '*')
                op = '*', p++;
            else if (*p == '/')
                op = '/', p++;
            else if (isspace(*p))
                p++;
        }

        if (op == '/' && value[1] == 0) {
            printf("Division by 0 exception\n");
            continue;
        }
        else
            result = calculate(value[0], op, value[1]);

        printf("%f %c %f = %f\n", value[0], op, value[1], result);
    }
}