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

void printLocalMaxima(int** a, int m, int n) {
	printf("Cac phan tu cuc dai:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int current = a[i][j];
			int isMaxima = 1;

			// Kiểm tra các phần tử lân cận
			for (int di = -1; di <= 1; di++) {
				for (int dj = -1; dj <= 1; dj++) {
					if (di == 0 && dj == 0) continue; // Bỏ qua phần tử hiện tại
					int ni = i + di;
					int nj = j + dj;
					if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
						if (a[ni][nj] >= current) {
							isMaxima = 0;
							break;
						}
					}
				}
				if (!isMaxima) break;
			}

			if (isMaxima) {
				printf("Phan tu cuc dai tai (%d, %d): %d\n", i, j, current);
			}
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

	printLocalMaxima(a, m, n);

	for (int i = 0; i < m; i++) {
		free(a[i]);
	}
	free(a);
	system("pause");
	return 0;
}