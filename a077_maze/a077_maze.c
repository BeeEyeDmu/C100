#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

enum Direction { DOWN, UP, LEFT, RIGHT };

typedef struct {
    int row, col;
} Coord;

Coord mEntrance;    // 출발점

Coord newCoord(int row, int col)
{
    Coord c = { row, col };
    return c;
}

Coord getEntrance(char** m, int rows, int columns)
{
    Coord entrance;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (m[i][j] == 'I') {
                entrance = newCoord(i, j);
                return entrance;
            }

    printf("No entrance found!\n");
    exit(1);
}

void printMaze(char** maze, int rows, int columns) 
{ 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            printf("%c", maze[i][j]);
        printf("\n");
    }
} 

// 진행할 방향(direction to proceed)을 찾는 함수
// 각 방향으로 진행할 장소가 있으면 poss[] 배열에 그 좌표를 저장하고 
// 더 이상 갈 곳이 없으면 poss[]를 (-1, -1)으로 만든다
void dirToProceed(Coord cur, char** maze, Coord* poss, int rows, int columns)
{
    /* DOWN */
    if (cur.row >= rows - 1)
        poss[DOWN] = newCoord(-1, -1);
    else {
        if (maze[cur.row + 1][cur.col] == ' ' ||
            maze[cur.row + 1][cur.col] == 'O')
            poss[DOWN] = newCoord(cur.row + 1, cur.col);
        else
            poss[DOWN] = newCoord(-1, -1);
    }

    /* UP */
    if (cur.row <= 0)
        poss[UP] = newCoord(-1, -1);
    else {
        if (maze[cur.row - 1][cur.col] == ' ' ||
            maze[cur.row - 1][cur.col] == 'O')
            poss[UP] = newCoord(cur.row - 1, cur.col);
        else
            poss[UP] = newCoord(-1, -1);
    }

    /* LEFT */
    if (cur.col <= 0)
        poss[LEFT] = newCoord(-1, -1);
    else {
        if (maze[cur.row][cur.col - 1] == ' ' ||
            maze[cur.row][cur.col - 1] == 'O')
            poss[LEFT] = newCoord(cur.row, cur.col - 1);
        else
            poss[LEFT] = newCoord(-1, -1);
    }

    /* RIGHT */
    if (cur.col >= columns - 1)
        poss[RIGHT] = newCoord(-1, -1);
    else {
        if (maze[cur.row][cur.col + 1] == ' ' ||
            maze[cur.row][cur.col + 1] == 'O')
            poss[RIGHT] = newCoord(cur.row, cur.col + 1);
        else
            poss[RIGHT] = newCoord(-1, -1);
    }
}

char isEqual(Coord c1, Coord c2)
{
    if ((c1.row == c2.row) && (c1.col == c2.col))
        return 1;
    else
        return 0;
}

// 미로가 찾아지면 경로를 출력하고 (-2, -2)를 리턴함
// (-2, -2)는 출구가 발견되었는지를 체크하기 위해 사용됨
Coord solveMaze(Coord cur, char** maze, int rows, int columns)
{
    Coord poss[4];  // D,U,L,R 방향으로 진행할 수 있는 다음 좌표
                     // 진행할 수 없으면 (-1,-1)
    Coord answer;

    if (cur.row == -1 && cur.col == -1)
        return cur;
    if (maze[cur.row][cur.col] == 'O')
        return newCoord(-2, -2);
    maze[cur.row][cur.col] = '.';

    dirToProceed(cur, maze, poss, rows, columns);
    for (int i = 0; i < 4; i++) {
        answer = solveMaze(poss[i], maze, rows, columns);
        if (answer.row == -1 && answer.col == -1)
            continue;
        if (answer.row == -2 && answer.col == -2) // 출구
            return answer;
    }

    // 백트래킹
    maze[cur.row][cur.col] = ' ';
    return cur;
}

int main()
{
    FILE* fp;
    char   filename[32];
    char** maze;
    int    nRows, nColumns;

    printf("미로 파일의 이름을 입력하세요 : ");
    scanf("%s", filename);

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("미로 파일을 못찾았습니다.\n");
        exit(1);
    }

    // 행과 열의 갯수를 입력받음 
    fscanf(fp, "%d", &nRows);
    fscanf(fp, "%d", &nColumns);

    maze = (char**)malloc(sizeof(char*) * nRows);
    for (int i = 0; i < nRows; i++)
        maze[i] = (char*)malloc(sizeof(char) * nColumns);

    // 파일에서 한 문자씩 읽어서 maze 배열에 저장
    fgetc(fp);  // '\n'을 제거
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nColumns; j++)
            maze[i][j] = fgetc(fp);
        fgetc(fp); // '\n'을 제거
    }
    fclose(fp);

    printMaze(maze, nRows, nColumns);

    mEntrance = getEntrance(maze, nRows, nColumns);
    Coord mExit = solveMaze(mEntrance, maze, nRows, nColumns);

    if (isEqual(mEntrance, mExit)) // 출발점으로 돌아왔으면 실패
        printf("미로 찾기 실패!\n");
    else {
        printf("미로 찾기 성공!\n");
        maze[mEntrance.row][mEntrance.col] = 'I'; /* 입구를 I로 바꿈 */
        printMaze(maze, nRows, nColumns);
    }
    for (int i = 0; i < nRows; i++)
        free(maze[i]);
    free(maze);
}