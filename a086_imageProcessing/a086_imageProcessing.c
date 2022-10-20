#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int width = 0;
int height = 0;
int bitCount = 0;
int bpp = 0;   // bytesPerPixel, 픽셀당 바이트수

BITMAPFILEHEADER hBmpFile; // hBmpFile
BITMAPINFOHEADER hBmpInfo; // hBmpInfo
RGBQUAD rgb[256];

FILE* ifp, * ofp;
BYTE* inImg;
BYTE* outImg;

typedef unsigned char BYTE;

void changeBrightness()
{
    int bright;
    printf("밝기 조절 값 : ");
    scanf("%d", &bright);

    for (int j = 0; j < height; j++)
        for (int i = 0; i < width; i++) {
            int newPic = *(inImg + (i + j * width) * bpp) + bright;
            if (newPic > 255)
                newPic = 255;
            if (newPic < 0)
                newPic = 0;
            *(outImg + (i + j * width) * bpp) = (BYTE)newPic;
        }
}

void changeContrast()
{
    int contrast, delta;

    printf("콘트라스트 조절 값(%) : ");
    scanf("%d", &contrast);

    for (int j = 0; j < height; j++)
        for (int i = 0; i < width; i++) {
            unsigned newPic = *(inImg + (i + j * width) * bpp);
            if (newPic > 127) {
                if ((newPic += (newPic - 127) * contrast / 100.) > 255)
                    newPic = 255;
            }
            else if (newPic < 127) {
                if ((newPic -= (127 - newPic) * contrast / 100.) < 0)
                    newPic = 0;
            }
            *(outImg + (i + j * width) * bpp) = newPic;
        }
}

void invert()
{
    for (int j = 0; j < height; j++)
        for (int i = 0; i < width; i++) {
            int newPic = 255 - *(inImg + (i + j * width) * bpp);
            *(outImg + (i + j * width) * bpp) = (BYTE)newPic;
        }
}

void menu()
{
    int choice;

    printf("\nImage Processing...\n");
    printf(" 1. 밝기 조절\n");
    printf(" 2. 콘트라스트\n");
    printf(" 3. 이미지 반전\n");
    printf("Choose Menu :");
    scanf("%d", &choice);

    switch (choice) {
    case 1: changeBrightness(); break;
    case 2: changeContrast(); break;
    case 3: invert(); break;
    }
}

int fileOpen()
{
    if ((ifp = fopen("lena_gray.bmp", "rb")) == NULL) {
        printf("Error opening lena_color.bmp");
        return 1;
    }
    if ((ofp = fopen("out.bmp", "wb")) == NULL) {
        printf("Error opening output file");
        return 1;
    }
    return 0;
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

void writeBMP()
{
    fwrite(&hBmpFile, sizeof(BITMAPFILEHEADER), 1, ofp);
    fwrite(&hBmpInfo, sizeof(BITMAPINFOHEADER), 1, ofp);
    fwrite(rgb, sizeof(RGBQUAD), 256, ofp);
    fwrite(outImg, width * height * bitCount / 8, 1, ofp);
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
    bitCount = hBmpInfo.biBitCount;
    bpp = bitCount / 8;

    inImg = (BYTE*)calloc(sizeof(BYTE), width * height * bpp);
    outImg = (BYTE*)calloc(sizeof(BYTE), width * height * bpp);

    fread(inImg, width * height * bpp, 1, ifp);

    menu();
    writeBMP();

    free(inImg);
    free(outImg);
    fclose(ifp);
    fclose(ofp);
}