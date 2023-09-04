/*
Астахова Анастасия Сергеевна
М8О-113Б-22
Вариант 2
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main() {
  int n = 5;
  printf("Введите размеры матрицы:\n");
  while (scanf("%d", &n)) {
    printf("Введите элементы матрицы\n");
    int matrix[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &matrix[i][j]);
      }
    }

    printf("Вывод:\n");
    int k = 0;
    while (k < n) {
      int j = n-1;
      for (int i = 0; i <= k; i++) {
        printf("%d ", matrix[i][j - k + i]);
      }
      k++;
    }

    int q = n-2;
    while (q >= 0) {
      int i = n - 1;
      for (int j = 0; j <= q; j++) {
        printf("%d ", matrix[i-q+j][j]);
      }
      q--;
    }
    printf("\nВведите размеры матрицы:\n");
  }
  return 0;
}
