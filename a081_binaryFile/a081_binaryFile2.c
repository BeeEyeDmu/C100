#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    FILE* ifp, * ofp;
    char buf[256];

    if ((ifp = fopen("bikang.png", "rb")) == NULL) {
        printf("Error opening \"bikang.png\"\n");
        exit(0);
    }

    ofp = fopen("out.png", "wb");

    while (fread(&buf, sizeof(buf), 1, ifp) != 0)
        fwrite(&buf, sizeof(buf), 1, ofp);

    printf("File copied successfully.\n");
    fclose(ifp);
    fclose(ofp);
}