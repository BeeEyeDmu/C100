#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <math.h>
#define COUNT 3

enum FigureType { CIRCLE, TRIANGLE, RECTANGLE };

struct figure {
    enum FigureType type;
    union {
        int radius;          // ������
        int tri_sides[3];    // ������ ����
        int rect_sides[2];   // ���� ����
    };
};

float area(struct figure* f)
{
    float area, s;
    switch (f->type)
    {
    case CIRCLE:
        area = 3.141592 * f->radius * f->radius;
        break;
    case TRIANGLE:
        s = (f->tri_sides[0] + f->tri_sides[1] + f->tri_sides[2]) / 2;
        area = sqrt(s * (s - f->tri_sides[0]) *
            (s - f->tri_sides[1]) * (s - f->tri_sides[2]));
        break;
    case RECTANGLE:
        area = f->rect_sides[0] * f->rect_sides[1];
        break;
    }
    return area;
}

void printFigure(struct figure* f)
{
    switch (f->type)
    {
    case CIRCLE:
        printf("�� ���� �������� %d, ������ %.2f�Դϴ�.\n",
            f->radius, area(f));
        break;
    case TRIANGLE:
        printf("�� �ﰢ�� ������ ���̴� %d, %d, %d, ������ %.2f�Դϴ�.\n",
            f->tri_sides[0], f->tri_sides[1], f->tri_sides[2], area(f));
        break;
    case RECTANGLE:
        printf("�� �簢���� �� ���� ���̴� %d, %d, ������ %.2f�Դϴ�.\n",
            f->rect_sides[0], f->rect_sides[1], area(f));
        break;
    }
}

// ���� �� ���� ���̴� �ٸ� �� �� ������ �պ��� �۾ƾ� �մϴ�
bool checkTriangle(struct figure fig)
{
    int max = 0;
    for (int i = 1; i <= 2; i++)
        if (max < fig.tri_sides[i])
            max = i;

    int otherSum = 0;
    for (int i = 0; i <= 2; i++)
        if (i != max)
            otherSum += fig.tri_sides[i];

    if (fig.tri_sides[max] < otherSum)
        return true;
    else
        return false;
}

int main()
{
    struct figure fig[COUNT];

    for (int i = 0; i < COUNT; i++) {
        printf("\n������ Ÿ����? (C:��, T:�ﰢ��, R:�簢��) : ");
        char type = _getche();

        switch (type) {
        case 'C':
            fig[i].type = CIRCLE;
            printf("\n �������� �Է��ϼ���: ");
            scanf("%d", &fig[i].radius);
            break;
        case 'T':
            fig[i].type = TRIANGLE;
            printf("\n �� ���� ���̸� �Է��ϼ���: ");
            scanf("%d%d%d", &fig[i].tri_sides[0],
                &fig[i].tri_sides[1], &fig[i].tri_sides[2]);
            if (checkTriangle(fig[i]) == false) {
                printf("�ﰢ���� �̷� �� �����ϴ�.");
                i--;
                continue;
            }
            break;
        case 'R':
            fig[i].type = RECTANGLE;
            printf("\n ���� ���̸� �Է��ϼ���: ");
            scanf("%d%d", &fig[i].rect_sides[0], &fig[i].rect_sides[1]);
            break;
        default:
            i--;
            break;
        }
    }

    for (int i = 0; i < COUNT; i++)
        printFigure(&fig[i]);
}