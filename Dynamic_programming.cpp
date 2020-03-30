#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

//商品資料型態
typedef struct {
	int serial;
	int price;
	int number;
} goods;

void input_menu(int isUse[], int sum, int startFlag, int** Start_backpack, int targetSum , int max);

void Average();

int main() {
	goods menu[50] = {
		{1,200,2},
		{2,150,3},
		{3,500,1},
		{4,70,2},
		{5,210,2},
		{-1,-1,-1}
	};
	int i, j, q, max;
	int targetSum = 350;
	int isUse[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int n = 0;
	for (i = 0;; i++) {
		if (menu[i].number != -1) {
			n = n + menu[i].number;
		}
		else break;
	}
	printf("%d", n);
	/*****************/
	int ** Start_backpack;
	Start_backpack = new int *[n];
	//因為是新增所以可以使用變數N
	/*****************/
	for (int i = 0; i < n; i++){
		Start_backpack[i] = new int[2];
	}

	for (i = 0, q = 0; i < 5; i++) {
		for (j = 1; j <= menu[i].number; j++) {
			Start_backpack[q][0] = menu[i].serial;
			Start_backpack[q][1] = menu[i].price;
			max = max + menu[i].price;
			q++;
		}
	}

	printf("number:%d\n", n);

	for (i = 0; i < n; i++) {
		printf("serial:%d,price:%d\n", Start_backpack[i][0], Start_backpack[i][1]);
	}

	input_menu(isUse, 0, 0, Start_backpack, targetSum , max);


	for (int i = 0; i < n; ++i)
		delete[] Start_backpack[i];
	delete[] Start_backpack;
}

void input_menu(int isUse[], int sum, int startFlag, int** Start_backpack, int targetSum , int max) {
	int i;
	//目前金額>=目標金額
	if (sum >= targetSum && sum <= max) {
		for (i = 0; i < 10; i++) {
			if (isUse[i] == 1) {
				printf("%d ", i);
			}
		}
		max = sum;
		printf("---");
		printf("%d\n", sum);
	}
	//目前金額<目標金額
	if (sum < targetSum) {
		for (i = startFlag; i < 10; i++) {
			if (isUse[i] == 0) {
				isUse[i] = 1;
				input_menu(isUse, sum + Start_backpack[i][1], i + 1, Start_backpack, targetSum , max);
				isUse[i] = 0;
			}
		}
	}
}

// 蕭同學的 git 測試
// 果雉雞的 git 測試
