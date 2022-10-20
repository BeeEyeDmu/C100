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
        int radius;          // 반지름
        int tri_sides[3];    // 세변의 길이
        int rect_sides[2];   // 가로 세로
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
        printf("이 원의 반지름은 %d, 면적은 %.2f입니다.\n",
            f->radius, area(f));
        break;
    case TRIANGLE:
        printf("이 삼각형 세변의 길이는 %d, %d, %d, 면적은 %.2f입니다.\n",
            f->tri_sides[0], f->tri_sides[1], f->tri_sides[2], area(f));
        break;
    case RECTANGLE:
        printf("이 사각형의 두 변의 길이는 %d, %d, 면적은 %.2f입니다.\n",
            f->rect_sides[0], f->rect_sides[1], area(f));
        break;
    }
}

// 가장 긴 변의 길이는 다른 두 변 길이의 합보다 작아야 합니다
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
        printf("\n도형의 타입은? (C:원, T:삼각형, R:사각형) : ");
        char type = _getche();

        switch (type) {
        case 'C':
            fig[i].type = CIRCLE;
            printf("\n 반지름을 입력하세요: ");
            scanf("%d", &fig[i].radius);
            break;
        case 'T':
            fig[i].type = TRIANGLE;
            printf("\n 세 변의 길이를 입력하세요: ");
            scanf("%d%d%d", &fig[i].tri_sides[0],
                &fig[i].tri_sides[1], &fig[i].tri_sides[2]);
            if (checkTriangle(fig[i]) == false) {
                printf("삼각형을 이룰 수 없습니다.");
                i--;
                continue;
            }
            break;
        case 'R':
            fig[i].type = RECTANGLE;
            printf("\n 폭과 높이를 입력하세요: ");
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