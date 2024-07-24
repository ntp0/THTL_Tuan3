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

void printMaxInColumns(int** a, int m, int n) {
	for (int j = 0; j < n; j++) {
		int max = a[0][j];
		for (int i = 1; i < m; i++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
		printf("Phan tu lon nhat o cot %d: %d\n", j, max);
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

	printf("\nPhan tu lon nhat tren tung cot:\n");
	printMaxInColumns(a, m, n);


	for (int i = 0; i < m; i++) {
		free(a[i]);
	}
	free(a);
	system("pause");
	return 0;
}