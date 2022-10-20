#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    FILE* ifp, * ofp;

    if ((ifp = fopen("bikang.png", "rb")) == NULL)
        printf("Error opening bikang.png\n");

    fseek(ifp, 0, SEEK_END);
    int length = ftell(ifp);

    fseek(ifp, 0, SEEK_SET);  // rewind(ifp) �� ����

    ofp = fopen("output.png", "wb");

    // fgetc, fputc�� ����ϴ� ���
    for (int i = 0; i < length; i++) {
        fputc(fgetc(ifp), ofp);
    }
    printf("File copied successfully.\n");
    fclose(ofp);

    // fread, fwrite�� ����ϴ� ���
    ofp = fopen("output1.png", "wb");
    rewind(ifp);

    char buf[256];

    while (fread(&buf, sizeof(buf), 1, ifp) != 0) {
        fwrite(&buf, sizeof(buf), 1, ofp);
    }

    printf("File copied successfully.\n");
    fclose(ifp);
    fclose(ofp);
}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main()
//{
//    FILE* ifp, * ofp;
//
//    if ((ifp = fopen("bikang.png", "rb")) == NULL) {
//        printf("Error opening \"bikang.png\"\n");
//        exit(0);
//    }
//
//    fseek(ifp, 0, SEEK_END);
//    int length = ftell(ifp);
//
//    fseek(ifp, 0, SEEK_SET);  // rewind(ifp) �� ����
//
//    ofp = fopen("output.png", "wb");
//
//    // fgetc, fputc�� ����ϴ� ���
//    for (int i = 0; i < length; i++) {
//        fputc(fgetc(ifp), ofp);
//    }
//    printf("File copied successfully.\n");
//    fclose(ofp);
//
//    // fread, fwrite�� ����ϴ� ���
//    rewind(ifp);
//    ofp = fopen("output1.png", "wb");
//
//    char buf[256];
//    while (fread(buf, sizeof(buf), 1, ifp) != 0) {
//        fwrite(buf, sizeof(buf), 1, ofp);
//    }
//
//    printf("File copied successfully.\n");
//    fclose(ifp);
//    fclose(ofp);
//}
