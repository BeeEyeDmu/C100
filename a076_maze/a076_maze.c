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

    printf("�̷� ������ �̸��� �Է��ϼ��� : ");
    scanf("%s", filename);

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("�̷� ������ ��ã�ҽ��ϴ�.\n");
        exit(1);
    }

    // ��� ���� ������ �Է¹��� 
    fscanf(fp, "%d", &nRows);
    fscanf(fp, "%d", &nColumns);

    maze = (char**)malloc(sizeof(char*) * nRows);
    for (int i = 0; i < nRows; i++)
        maze[i] = (char*)malloc(sizeof(char) * nColumns);

    // ���Ͽ��� �� ���ھ� �о maze �迭�� ����
    fgetc(fp);          // '\n'�� ����
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nColumns; j++) {
            maze[i][j] = fgetc(fp);
        }
        fgetc(fp);      // '\n'�� ����
    }
    fclose(fp);

    printMaze(maze, nRows, nColumns);

    for (int i = 0; i < nRows; i++)
        free(maze[i]);
    free(maze);
}