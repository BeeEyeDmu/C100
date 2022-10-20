#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

BITMAPFILEHEADER hBmpFile; // hBmpFile
BITMAPINFOHEADER hBmpInfo; // hBmpInfo

FILE* ifp;

typedef struct RGB {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} sRGB;

typedef struct image {
    int width;
    int height;
    struct RGB** pixel;
} sImage;

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

unsigned char grayscale(struct RGB pixel) {
    return (pixel.red + pixel.green + pixel.blue) / 3;
}

void imageToText(sImage img) {
    unsigned char gs;
    // 0~31, 32~63,.. 32단위로 어둡기를 표현
    char textPixel[] = { '@', '#', '%', 'O', 'a', '-', '.', ' ' };
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            gs = grayscale(img.pixel[i][j]);
            printf("%c", textPixel[7 - gs / 32]);
        }
        printf("\n");
    }
}

sImage readImage(FILE* fp, int width, int height) {
    sImage img;
    img.width = width;
    img.height = height;
    img.pixel = (sRGB**)calloc(height, sizeof(sRGB*));

    int bytesInARow = ((24 * width + 31) / 32) * 4;  // padding을 고려
    for (int i = height - 1; i >= 0; i--) {
        img.pixel[i] = (sRGB*)calloc(width, sizeof(sRGB));
        fread(img.pixel[i], bytesInARow, sizeof(BYTE), fp);
    }
    return img;
}

int main()
{
    if ((ifp = fopen("fruit.bmp", "rb")) == NULL) {
        printf("Error opening fruit.bmp");
        return 1;
    }

    fread(&hBmpFile, sizeof(BITMAPFILEHEADER), 1, ifp);
    if (checkBMP() == 1) return 1;
    fread(&hBmpInfo, sizeof(BITMAPINFOHEADER), 1, ifp);
    printBMPInfo();

    sImage img = readImage(ifp, hBmpInfo.biWidth, hBmpInfo.biHeight);

    imageToText(img);
    fclose(ifp);
}