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

int main() {
	int n;

	// Nhập cấp của ma trận
	printf("Nhap cap cua ma tran (n >= 5): ");
	scanf("%d", &n);

	if (n < 5) {
		printf("Cap cua ma tran phai lon hon hoac bang 5.\n");
		return 1;
	}

	// Khai báo và cấp phát ma trận vuông cấp n
	int **maTran = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		maTran[i] = (int *)malloc(n * sizeof(int));
	}

	// Tạo ma trận và xuất ra màn hình
	taoMaTranVuong(n, maTran);
	printf("Ma tran vuong cap %d:\n", n);
	xuatMaTranVuong(n, maTran);

	// Giải phóng bộ nhớ
	for (int i = 0; i < n; i++) {
		free(maTran[i]);
	}
	free(maTran);

	return 0;
}