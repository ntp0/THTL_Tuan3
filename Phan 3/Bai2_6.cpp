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

// Hàm sắp xếp các phần tử trên đường chéo chính theo thứ tự tăng dần
void sapXepDuongCheoChinh(int n, int **maTran) {
	int *duongCheoChinh = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		duongCheoChinh[i] = maTran[i][i];
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (duongCheoChinh[i] > duongCheoChinh[j]) {
				int temp = duongCheoChinh[i];
				duongCheoChinh[i] = duongCheoChinh[j];
				duongCheoChinh[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		maTran[i][i] = duongCheoChinh[i];
	}

	free(duongCheoChinh);
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

	sapXepDuongCheoChinh(n, maTran);
	printf("Ma tran sau khi sap xep duong cheo chinh:\n");
	xuatMaTranVuong(n, maTran);

	for (int i = 0; i < n; i++) {
		free(maTran[i]);
	}
	free(maTran);
	system("pause");
	return 0;
}