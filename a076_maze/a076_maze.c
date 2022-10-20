#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void printMaze(char** maze, int rows, int columns)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            printf("%c", maze[i][j]);
        printf("\n");
    }
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
    fgetc(fp);          // '\n'을 제거
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nColumns; j++) {
            maze[i][j] = fgetc(fp);
        }
        fgetc(fp);      // '\n'을 제거
    }
    fclose(fp);

    printMaze(maze, nRows, nColumns);

    for (int i = 0; i < nRows; i++)
        free(maze[i]);
    free(maze);
}