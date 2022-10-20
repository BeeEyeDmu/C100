#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

BITMAPFILEHEADER hBmpFile;
BITMAPINFOHEADER hBmpInfo;

typedef unsigned char BYTE;
FILE* ifp, * ofp;
BYTE* inImg;

typedef struct RGB {
    BYTE blue;
    BYTE green;
    BYTE red;
} sRGB;

typedef struct image {
    int width;
    int height;
    sRGB** pixel;
} sImage;

int fileOpen()
{
    if ((ifp = fopen("lena_color.bmp", "rb")) == NULL) {
        printf("Error opening lena_color.bmp");
        return 1;
    }
    if ((ofp = fopen("lena_gray.bmp", "wb")) == NULL) {
        printf("Error opening output file");
        return 1;
    }
    return 0;
}

sImage readImage(FILE* fp, int width, int height) {
    sImage img;
    img.width = width;
    img.height = height;
    img.pixel = (sRGB**)calloc(height, sizeof(sRGB*));

    // padding을 고려한 total number of bytes
    int bytesInARow = ((24 * width + 31) / 32) * 4;
    for (int i = height - 1; i >= 0; i--) {
        img.pixel[i] = (sRGB*)calloc(width, sizeof(sRGB));
        fread(img.pixel[i], bytesInARow, sizeof(BYTE), fp);
    }
    return img;
}

unsigned char grayscale(sRGB pixel) {
    return (pixel.red + pixel.green + pixel.blue) / 3;
}

void colorToGrayscale(sImage img)
{
    for (int i = 0; i < img.height; i++)
        for (int j = 0; j < img.width; j++)
            img.pixel[i][j].red =
            img.pixel[i][j].green =
            img.pixel[i][j].blue = grayscale(img.pixel[i][j]);
}

void writeGrayscale(sImage img) {
    fwrite(&hBmpFile, sizeof(BITMAPFILEHEADER), 1, ofp);
    fwrite(&hBmpInfo, sizeof(BITMAPINFOHEADER), 1, ofp);

    int bytesInARow = ((24 * img.width + 31) / 32) * 4;
    // image 쓰기
    for (int i = img.height - 1; i >= 0; i--) {
        fwrite(img.pixel[i], bytesInARow, sizeof(BYTE), ofp);
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

int main()
{
    if (fileOpen() == 1) return 1;
    fread(&hBmpFile, sizeof(BITMAPFILEHEADER), 1, ifp);
    if (checkBMP() == 1) return 1;
    fread(&hBmpInfo, sizeof(BITMAPINFOHEADER), 1, ifp);

    printBMPInfo();

    int width = hBmpInfo.biWidth;
    int height = hBmpInfo.biHeight;
    sImage img = readImage(ifp, width, height);

    colorToGrayscale(img);
    writeGrayscale(img);

    fclose(ifp);
    fclose(ofp);
}