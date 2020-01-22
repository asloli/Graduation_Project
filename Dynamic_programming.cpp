#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Lowest_price(int cata[][3]);
void Average();
int main() {
	/*struct catalog {			//宣告商品清單屬性 1.編號 2.商品名 3.價格 4.數量
		int asID;
		char name;
		int money;
		int amount;
	};
	struct catalog tags[10]{	//測試用清單
		{1, 'A', 200, 2},
		{2, 'B', 150, 3},
		{3, 'C', 500, 1},
		{4, 'D', 70, 2},
		{5, 'E', 210, 2}
	};
	int totalTags = sizeof(tags) / sizeof(catalog);	//檢查清單數量*/
	//測試用商品清單1.編號 2.價格 3.數量
	int cata[10][3] = {{1,200,2},
					   {2,150,3},
					   {3,500,1},
					   {4,70,2},
					   {5,210,2}};
	for (int i = 0; i < 5; i++){
		printf("二維陣列cata的第%d列:%d,%d,%d\n", i, cata[i][0], cata[i][1], cata[i][2]);
	}
	//使用氣泡排序法以價格為基準重新排序 
	int temp;
	for (int x = 1; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (cata[y][1] < cata[y + 1][1]) {
				for (int z = 0; z < 3; z++) {
					temp = cata[y+1][z];
					cata[y+1][z] = cata[y][z];
					cata[y][z] = temp;
				}
			}
		}
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		printf("二維陣列cata的第%d列:%d,%d,%d\n", i, cata[i][0], cata[i][1], cata[i][2]);
	}
	printf("\n");
	Lowest_price(cata);
}

//全都可買可不買，訂下最低消費額
void Lowest_price(int arr[][3]){
	int Start_backpack[100][3] = { 0,0,false };	//空背包 1.編號 2.價格 3.拿和不拿
	int End_backpack[100][3]   = { 0,0,false };	//最終會回傳給主程式的答案
	int Target_amount = 350;					//目標金額
	int Max_amount    = 0;						//最大總額
	int A[100];									//計算動態規劃時用的暫存背包
	int n = 0;									//商品的數量
	//將上面的變數匯入cata[][]的資訊
	for (int i = 0, q = 0; i < 5; i++){
		for (int j = 1; j <= arr[i][2]; j++) {
			Start_backpack[q][0] = arr[i][0];
			Start_backpack[q][1] = arr[i][1];
			Start_backpack[q][2] = false;
			Max_amount = Max_amount + arr[i][1];
			q++;
		}
		n = n + arr[i][2];
	}
	printf("目前有%d項商品\n", n);
	for (int i = 0; i < n; i++) {
		printf("商品編號:%d,金額:%d\n", Start_backpack[i][0], Start_backpack[i][1]);
	}
	//以動態規劃的方式搜尋最佳解
	for (int i = 0; i < n; i++) {
		int now_amount = 0;				//每一輪都將金額歸零
		A[i] = Start_backpack[i][1];	//將第一項商品金額移入A[]
		Start_backpack[i][2] = true;	//將false -> true 表示這項有拿
		for (int j = 0; j <= n; i++) {	//紀錄所有 true 的金額加總
			if (Start_backpack[j][2] = true) {
				now_amount = now_amount + A[j];
			}
		}
		if (now_amount >= Target_amount && now_amount <= Max_amount) {
			Start_backpack[i][2] = !Start_backpack[i][2];

		}
	}
}

//必買物的拆帳(2份)
void Average() {

}