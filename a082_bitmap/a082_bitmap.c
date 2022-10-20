#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

BITMAPFILEHEADER hBmpFile;
BITMAPINFOHEADER hBmpInfo;

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
    FILE* ifp, * ofp;
    RGBTRIPLE** image;
    int width = 0;
    int height = 0;

    if ((ifp = fopen("lena_gray.bmp", "rb")) == NULL) {
        printf("Error opening Lenna.bmp");
        return 1;
    }
    if ((ofp = fopen("output.bmp", "wb")) == NULL) {
        printf("Error opening output file");
        return 1;
    }
    fread(&hBmpFile, sizeof(BITMAPFILEHEADER), 1, ifp);
    if (checkBMP() == 1) { return 1; }
    fread(&hBmpInfo, sizeof(BITMAPINFOHEADER), 1, ifp);

    width = hBmpInfo.biWidth;
    height = hBmpInfo.biHeight;
    printBMPInfo();

    fwrite(&hBmpFile, sizeof(BITMAPFILEHEADER), 1, ofp);
    fwrite(&hBmpInfo, sizeof(BITMAPINFOHEADER), 1, ofp);

    image = (RGBTRIPLE**)calloc(sizeof(RGBTRIPLE*), height);
    for (int i = 0; i < height; i++) {
        image[i] = (RGBTRIPLE*)calloc(sizeof(RGBTRIPLE), width);
        fread(image[i], sizeof(RGBTRIPLE), width, ifp);
    }

    for (int i = 0; i < height; i++)
        fwrite(image[i], sizeof(RGBTRIPLE), width, ofp);

    for (int i = 0; i < height; i++)
        free(image[i]);
    free(image);

    fclose(ifp);
    fclose(ofp);
}