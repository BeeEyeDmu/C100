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

extern menuItem* menuItemList;			// 커피메뉴의 연결리스트
extern orderNode* orderList;	// 주문의 연결리스트

void loadCoffeeMenu();		// 커피 메뉴 읽어오기
void insertCoffeeMenu(int id, const char* menuName, int price);	// 커피 메뉴를 리스트에 추가
void showMainMenu();		// 메인 메뉴 보여주기
void showCoffeeMenuList();	// 1번 메뉴(커피 메뉴 보기)
void showCoffeeMenu();		// menuItemList의 내용 출력
void waitZeroInput();		// 0을 입력할 때까지 대기
void showOrders();			// orderList의 내용 출력
saleNode* addSales(saleNode* saleToday, orderNode* p);	// saleToday 리스트에 추가

/*
//int  passwordCheck();		// 암호 체크
void loadCoffeeMenu();		// 커피 메뉴 읽어오기
void insertCoffeeMenu(int id, const char* menuName, int price);	// 커피 메뉴를 리스트에 추가
//int  deleteCoffeeMenu();	// 커피 메뉴 삭제
//void mainMenu();			// 메인 메뉴 선택과 처리
void showMainMenu();		// 메인 메뉴 보여주기
void showCoffeeMenuList();	// 1번 메뉴(커피 메뉴 보기)
void showCoffeeMenu();		// menuItemList의 내용 출력
//int  close();				// 0번 메뉴(끝내기)
void waitZeroInput();		// 0을 입력할 때까지 대기
//void showSaleToday();		// 오늘의 매출 보기
//void showOrderList();		// 4번 메뉴(주문 목록 확인)
void showOrders();			// orderList의 내용 출력
//void saveMenuFile();		// 커피 메뉴를 파일에 저장
saleNode* addSales(saleNode* saleToday, orderNode* p);	// saleToday 리스트에 추가
*/

#endif