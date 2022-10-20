//#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
//#endif
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
    char* buffer;
    size_t fsize;

    FILE* fp = fopen("test.txt", "rb");
    FILE* ofp = fopen("output.txt", "wb");
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    printf("size of \"test.txt\" file is %zu bytes\n", fsize);

    buffer = (char*)malloc(fsize);
    memset(buffer, 0, fsize); // buffer�� 0���� �ʱ�ȭ

    rewind(fp);   // fseek(fp, 0, SEEK_SET);�� ����
    fread(buffer, fsize, 1, fp);

    fwrite(buffer, fsize, 1, ofp);

    fclose(fp);
    fclose(ofp);
    free(buffer);
    printf("\"test.txt\" file is copied to \"output.txt\" file\n");
}