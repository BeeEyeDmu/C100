#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define POINTS  100     // 점의 개수
#define MAXPOS  1000    // 최대 좌표

typedef struct point {
    int x;
    int y;
} point;

typedef struct pointPair {
    double dist;
    point p1;
    point p2;
} pointPair;

point p[POINTS];

double dist(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x)
        + (p1.y - p2.y) * (p1.y - p2.y));
}

pointPair makePair(point p1, point p2)
{
    pointPair pp;

    pp.dist = dist(p1, p2);
    pp.p1 = p1;
    pp.p2 = p2;
    return pp;
}

pointPair closestPair()
{
    double min = MAXPOS * MAXPOS, d;
    pointPair minPair;

    for (int i = 0; i < POINTS - 1; i++)
        for (int j = i + 1; j < POINTS; j++)
            if ((d = dist(p[i], p[j])) < min) {
                min = d;
                minPair = makePair(p[i], p[j]);
            }
    return minPair;
}

int main()
{
    srand(time(0));	// 랜덤 시드 설정
    for (int i = 0; i < POINTS; i++) {
        p[i].x = rand() % MAXPOS;
        p[i].y = rand() % MAXPOS;
    }

    pointPair pp = closestPair();
    printf("closest pair : (%d,%d)-(%d,%d) distance = %f\n",
        pp.p1.x, pp.p1.y, pp.p2.x, pp.p2.y, pp.dist);
}