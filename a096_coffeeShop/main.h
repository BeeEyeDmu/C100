#ifndef MAIN_H
#define MAIN_H
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include "data.h"

extern menuItem* menuItemList;			// Ŀ�Ǹ޴��� ���Ḯ��Ʈ
extern orderNode* orderList;	// �ֹ��� ���Ḯ��Ʈ

void loadCoffeeMenu();		// Ŀ�� �޴� �о����
void insertCoffeeMenu(int id, const char* menuName, int price);	// Ŀ�� �޴��� ����Ʈ�� �߰�
void showMainMenu();		// ���� �޴� �����ֱ�
void showCoffeeMenuList();	// 1�� �޴�(Ŀ�� �޴� ����)
void showCoffeeMenu();		// menuItemList�� ���� ���
void waitZeroInput();		// 0�� �Է��� ������ ���
void showOrders();			// orderList�� ���� ���
saleNode* addSales(saleNode* saleToday, orderNode* p);	// saleToday ����Ʈ�� �߰�

/*
//int  passwordCheck();		// ��ȣ üũ
void loadCoffeeMenu();		// Ŀ�� �޴� �о����
void insertCoffeeMenu(int id, const char* menuName, int price);	// Ŀ�� �޴��� ����Ʈ�� �߰�
//int  deleteCoffeeMenu();	// Ŀ�� �޴� ����
//void mainMenu();			// ���� �޴� ���ð� ó��
void showMainMenu();		// ���� �޴� �����ֱ�
void showCoffeeMenuList();	// 1�� �޴�(Ŀ�� �޴� ����)
void showCoffeeMenu();		// menuItemList�� ���� ���
//int  close();				// 0�� �޴�(������)
void waitZeroInput();		// 0�� �Է��� ������ ���
//void showSaleToday();		// ������ ���� ����
//void showOrderList();		// 4�� �޴�(�ֹ� ��� Ȯ��)
void showOrders();			// orderList�� ���� ���
//void saveMenuFile();		// Ŀ�� �޴��� ���Ͽ� ����
saleNode* addSales(saleNode* saleToday, orderNode* p);	// saleToday ����Ʈ�� �߰�
*/

#endif