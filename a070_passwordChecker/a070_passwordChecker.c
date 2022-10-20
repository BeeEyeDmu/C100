#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int passwordChecker(char password[]);

int main()
{
    char password[30];

    while (1) {
        printf("�н����� �Է�(8���� �̻�, ��ҹ���/����/Ư������ ����): ");
        //scanf_s("%s", password, sizeof(password));
        scanf("%s", password);

        switch (passwordChecker(password)) {
        case 1:
            printf("8���� �̻��̾�� �մϴ�.\n");
            break;
        case 2:
            printf("���� �빮�ڰ� �ϳ� �̻��̾�� �մϴ�.\n");
            break;
        case 3:
            printf("���� �ҹ��ڰ� �ϳ� �̻��̾�� �մϴ�.\n");
            break;
        case 4:
            printf("���ڰ� �ϳ� �̻��̾�� �մϴ�.\n");
            break;
        case 5:
            printf("Ư�����ڰ� �ϳ� �̻��̾�� �մϴ�.\n");
            break;
        default:
            printf("��Ģ�� �´� �н������Դϴ�.\n");
            return 0;
        }
    }
}

int passwordChecker(char password[])
{
    int checkUpper = 0;
    int checkLower = 0;
    int checkSpecial = 0;
    int checkDigit = 0;

    if (strlen(password) < 8)
        return 1;

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i]))
            checkUpper = 1;
        else if (islower(password[i]))
            checkLower = 1;
        else if (isdigit(password[i]))
            checkDigit = 1;
        else
            checkSpecial = 1;
    }

    if (checkUpper == 0) return 2;
    if (checkLower == 0) return 3;
    if (checkLower == 0) return 3;
    if (checkDigit == 0) return 4;
    if (checkSpecial == 0) return 5;
    return 0;
}