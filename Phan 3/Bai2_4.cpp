#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>


// Hàm tạo ma trận vuông cấp n với các số nguyên ngẫu nhiên
void taoMaTranVuong(int n, int **maTran) {
	srand(time(NULL)); // Khởi tạo bộ sinh số ngẫu nhiên
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			maTran[i][j] = rand() % 100 + 1; // Số ngẫu nhiên từ 1 đến 100
		}
	}
}

// Hàm xuất ma trận vuông ra màn hình
void xuatMaTranVuong(int n, int **maTran) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d ", maTran[i][j]);
		}
		printf("\n");
	}
}

// Hàm tìm phần tử lớn nhất thuộc tam giác trên của đường chéo chính
int timMaxTamGiacTren(int n, int **maTran) {
	int max = maTran[0][1]; 

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (maTran[i][j] > max) {
				max = maTran[i][j];
			}
		}
	}

	return max;
}

int main() {
	int n;

	printf("Nhap cap cua ma tran (n >= 5): ");
	scanf("%d", &n);

	if (n < 5) {
		printf("Cap cua ma tran phai lon hon hoac bang 5.\n");
		return 1;
	}

	int **maTran = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		maTran[i] = (int *)malloc(n * sizeof(int));
	}

	taoMaTranVuong(n, maTran);
	printf("Ma tran vuong cap %d:\n", n);
	xuatMaTranVuong(n, maTran);

	int max = timMaxTamGiacTren(n, maTran);
	printf("Phan tu lon nhat thuoc tam giac tren duong cheo chinh la: %d\n", max);

	for (int i = 0; i < n; i++) {
		free(maTran[i]);
	}
	free(maTran);
	system("pause");
	return 0;
}