#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int fsize;

    FILE* fp = fopen("test.txt", "r");

    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    printf("filesize of \"test.txt\" = %d bytes\n", fsize);

    fseek(fp, 0, SEEK_SET);
    printf("fp = %d\n", ftell(fp));

    fseek(fp, -10, SEEK_CUR);
    printf("fp = %d\n", ftell(fp));

    fseek(fp, 10, SEEK_END);
    printf("fp = %d\n", ftell(fp));

    fclose(fp);
}