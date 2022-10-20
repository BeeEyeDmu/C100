#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

BITMAPFILEHEADER hBmpFile;
BITMAPINFOHEADER hBmpInfo;
FILE* ifp, * ofp;

int fileOpen()
{
    if ((ifp = fopen("lena_color.bmp", "rb")) == NULL) {
        printf("Error opening lena_color.bmp");
        return 1;
    }
    if ((ofp = fopen("lena_8bit.bmp", "wb")) == NULL) {
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

int error() {
    fclose(ofp);
    fclose(ifp);
    return 0;
}

void checkOutput()
{
    if ((ifp = fopen("lena_8bit.bmp", "rb")) == NULL) {
        printf("Error opening lena_8bit.bmp");
        return 1;
    }

    printf("\nlena_8bit.bmp 정보\n");

    fread(&hBmpFile, sizeof hBmpFile, 1, ifp);
    fread(&hBmpInfo, sizeof hBmpInfo, 1, ifp);
    if (checkBMP() == 1) return 1;

    printBMPInfo();
}

int main()
{
    int width, height;

    if (fileOpen() == 1) return 1;

    fread(&hBmpFile, sizeof hBmpFile, 1, ifp);
    fread(&hBmpInfo, sizeof hBmpInfo, 1, ifp);

    if (checkBMP() == 1) return 1;

    width = hBmpInfo.biWidth;
    height = hBmpInfo.biHeight;

    printBMPInfo();

    if (hBmpInfo.biBitCount != 24)
    {
        printf("입력파일이 24비트 포맷이 아닙니다.\n");
        error();
    }

    // width in bytes
    int srcBytesInARow = ((width * 24 + 31) / 32) * 4;
    int dstBytesInARow = ((width * 8 + 31) / 32) * 4;

    BYTE* src = (BYTE*)malloc(srcBytesInARow * height);
    BYTE* dst = (BYTE*)malloc(dstBytesInARow * height);

    //read pixels
    fread(src, 1, srcBytesInARow * height, ifp);

    //make gray scale color-table
    BYTE colorTable[1024] = { 0 };
    for (int i = 0; i < 256; i++)
        colorTable[i * 4 + 0] = colorTable[i * 4 + 1]
        = colorTable[i * 4 + 2] = (BYTE)i;

    for (int y = height - 1; y >= 0; y--)
    {
        for (int x = 0; x < width; x++)
        {
            BYTE b = src[y * srcBytesInARow + x * 3 + 0];
            BYTE g = src[y * srcBytesInARow + x * 3 + 1];
            BYTE r = src[y * srcBytesInARow + x * 3 + 2];
            BYTE gray = (BYTE)(.33 * r + .34 * g + .33 * b);
            dst[y * dstBytesInARow + x] = gray;
        }
    }
    // modify headers
    //hBmpFile.bfSize = 14 + 40 + 1024 + dstBytesInARow * height;
    hBmpFile.bfSize = sizeof(hBmpFile) + sizeof(hBmpInfo) + sizeof(colorTable) + dstBytesInARow * height;
    hBmpFile.bfOffBits
        = sizeof(hBmpFile) + sizeof(hBmpInfo) + sizeof(colorTable);
    hBmpInfo.biBitCount = 8;
    hBmpInfo.biSizeImage = dstBytesInARow * height;

    // write output file
    fwrite(&hBmpFile, sizeof(hBmpFile), 1, ofp);
    fwrite(&hBmpInfo, sizeof(hBmpInfo), 1, ofp);
    fwrite(colorTable, 1, 1024, ofp);
    fwrite(dst, 1, dstBytesInARow * height, ofp);

    free(src);
    free(dst);
    fclose(ofp);
    fclose(ifp);

    // output file의 정보를 출력
    checkOutput();
}