#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

FILE* ifp, * ofp;
unsigned char** inImg;
unsigned char** outImg;

BITMAPFILEHEADER hBmpFile; // hBmpFile
BITMAPINFOHEADER hBmpInfo; // hBmpInfo
RGBQUAD rgb[256];   // Color Table

int width = 0;
int height = 0;
int bitCount = 0;

void writeImage(int width, int height)
{
    for (int i = height - 1; i >= 0; i--)
        fwrite(outImg[i], width, sizeof(unsigned char), ofp);
}

void freeImage(int w, int h) {
    for (int i = 0; i < height; i++)
        free(inImg[i]);
    free(inImg);
    for (int i = 0; i < h; i++)
        free(outImg[i]);
    free(outImg);
}

void writeHeader()
{
    fwrite(&hBmpFile, sizeof(BITMAPFILEHEADER), 1, ofp);
    fwrite(&hBmpInfo, sizeof(BITMAPINFOHEADER), 1, ofp);
    fwrite(rgb, sizeof(RGBQUAD), 256, ofp);
}

void changeHeader(int w, int h)
{
    hBmpInfo.biWidth = w;
    hBmpInfo.biHeight = h;
    hBmpFile.bfSize = sizeof(hBmpInfo) + sizeof(hBmpFile)
        + sizeof(rgb) + w * h;
}

void xMirroring()
{
    outImg = (unsigned char**)calloc(height, sizeof(unsigned char*));
    for (int i = height - 1; i >= 0; i--) {
        outImg[i] = (unsigned char*)calloc(width, sizeof(unsigned char));
        for (int j = 0; j < width; j++)
            outImg[i][width - j - 1] = inImg[i][j];
    }
    writeHeader();
    writeImage(width, height);
    freeImage(width, height);
}

void yMirroring()
{
    outImg = (unsigned char**)calloc(height, sizeof(unsigned char*));
    for (int i = 0; i < height; i++)
        outImg[i] = (unsigned char*)calloc(width, sizeof(unsigned char));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            outImg[height - i - 1][j] = inImg[i][j];
    }
    writeHeader();
    writeImage(width, height);
    freeImage(width, height);
}

void crop()
{
    int h = height / 2;
    int w = width / 2;
    w = ((w * 8 + 31) / 32) * 4;

    changeHeader(w, h);
    writeHeader();

    outImg = (unsigned char**)calloc(h, sizeof(unsigned char*));
    for (int i = 0; i < h; i++)
        outImg[i] = (unsigned char*)calloc(w, sizeof(unsigned char));

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            outImg[i][j] = inImg[w - 2 / w + i][h - h / 2 + j];

    writeImage(w, h);
    freeImage(w, h);
}

void resize(float f)
{
    int h = (int)(height * f);
    int w = (int)(width * f);
    w = ((w * 8 + 31) / 32) * 4; // 패딩

    changeHeader(w, h);
    writeHeader();

    outImg = (unsigned char**)calloc(h, sizeof(unsigned char*));
    for (int i = 0; i < h; i++)
        outImg[i] = (unsigned char*)calloc(w, sizeof(unsigned char));

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            outImg[i][j] = inImg[(int)(i / f)][(int)(j / f)];

    writeImage(w, h);
    freeImage(w, h);
}

void menu()
{
    int choice;

    printf("\nImage Processing...\n");
    printf(" 1. 좌우 반전\n");
    printf(" 2. 상하 반전\n");
    printf(" 3. 이미지 자르기\n");
    printf(" 4. 이미지 축소\n");
    printf(" 5. 이미지 확대\n");
    printf("Choose Menu :");
    scanf("%d", &choice);

    switch (choice) {
    case 1: xMirroring(); break;
    case 2: yMirroring(); break;
    case 3: crop(); break;
    case 4: resize(0.5); break;
    case 5: resize(1.5); break;
    }
}

int checkBMP()
{
    if (hBmpFile.bfType == 0x4D42) { // 아스키 값으로 BM
        printf("BMP 파일입니다.\n");
        return 0;
    }
    else {
        printf("BMP 파일이 아닙니다.\n");
        return 1;
    }
}

void printBMPInfo()
{
    printf("file.bfSize = %d\n", hBmpFile.bfSize);
    printf("file.bfType = %x\n", hBmpFile.bfType);
    printf("file.bfOffBits = %d\n", hBmpFile.bfOffBits);
    printf("info.biSize = %d\n", hBmpInfo.biSize);
    printf("info.biWidth = %d\n", hBmpInfo.biWidth);
    printf("info.biHeight = %d\n", hBmpInfo.biHeight);
    printf("info.biBitCount = %d\n", hBmpInfo.biBitCount);
    printf("info.biCompression = %d\n", hBmpInfo.biCompression);
    printf("info.biSizeImage = %d\n", hBmpInfo.biSizeImage);
    printf("filesize - imagesize = %d\n", hBmpFile.bfSize - hBmpInfo.biSizeImage);
}

int fileOpen()
{
    if ((ifp = fopen("lena_gray.bmp", "rb")) == NULL) {
        printf("Error opening lena_gray.bmp");
        return 1;
    }
    if ((ofp = fopen("output.bmp", "wb")) == NULL) {
        printf("Error opening output file");
        return 1;
    }
    return 0;
}

int main()
{
    if (fileOpen() == 1) return 1;

    fread(&hBmpFile, sizeof(BITMAPFILEHEADER), 1, ifp);
    if (checkBMP() == 1) return 1;

    fread(&hBmpInfo, sizeof(BITMAPINFOHEADER), 1, ifp);
    fread(rgb, sizeof(RGBQUAD), 256, ifp);
    printBMPInfo();

    width = hBmpInfo.biWidth;
    height = hBmpInfo.biHeight;

    // inImg 메모리 할당과 이미지 읽어오기
    inImg = (unsigned char**)calloc(height, sizeof(unsigned char*));
    for (int i = height - 1; i >= 0; i--) {
        inImg[i] = (unsigned char*)calloc(width, sizeof(unsigned char));
        fread(inImg[i], width, 1, ifp);
    }

    menu();
    printf("output.bmp saved!");

    fclose(ifp);
    fclose(ofp);
}