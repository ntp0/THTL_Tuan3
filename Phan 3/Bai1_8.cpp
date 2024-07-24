#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

void createRandomMatrix(int** a, int m, int n, int k) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % (k + 1);
		}
	}
}

void printMatrix(int** a, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}

// Hàm xuất các dòng chỉ chứa số chẵn
void printEvenRows(int** a, int m, int n) {
	printf("Cac dong chi chua so chan:\n");
	for (int i = 0; i < m; i++) {
		int isEvenRow = 1;
		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 != 0) {
				isEvenRow = 0;
				break;
			}
		}
		if (isEvenRow) {
			for (int j = 0; j < n; j++) {
				printf("%4d", a[i][j]);
			}
			printf("\n");
		}
	}
}


int main() {
	int m, n, k;
	srand(time(0));

	printf("Nhap so dong cua ma tran (m): ");
	scanf("%d", &m);
	printf("Nhap so cot cua ma tran (n): ");
	scanf("%d", &n);
	printf("Nhap gia tri lon nhat cua cac phan tu (k): ");
	scanf("%d", &k);

	int** a = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}

	createRandomMatrix(a, m, n, k);
	printf("Ma tran ngau nhien:\n");
	printMatrix(a, m, n);

	printEvenRows(a, m, n);

	for (int i = 0; i < m; i++) {
		free(a[i]);
	}
	free(a);
	system("pause");
	return 0;
}