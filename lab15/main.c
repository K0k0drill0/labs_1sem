/*
Астахова Анастасия Сергеевна
М8О-113Б-22
замена всех максимальных элементов матрицы на число столбцов, содержащих её
минимальный элемент
*/
#include <stdio.h>

#define INF 1e9;
#define EPS 1e-9;

void scanMatr(int n, int matr[n][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &matr[i][j]);
    }
  }
}

void showMatr(int n, int matr[n][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int n;
  printf("Введите размерность матрицы: \n");
  while (scanf("%d", &n)) {
    printf("Введите матрицу: \n");
    int matr[n][n];
    scanMatr(n, matr);
    int maxim = EPS;
    int mini = INF;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (matr[i][j] > maxim) {
          maxim = matr[i][j];
        }
        if (matr[i][j] < mini) {
          mini = matr[i][j];
        }
      }
    }
    int col_with_min = 0;
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        if (matr[i][j] == mini) {
          col_with_min++;
          break;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (matr[i][j] == maxim) {
          matr[i][j] = col_with_min;
        }
      }
    }
    printf("Полученная матрица:\n");
    showMatr(n, matr);
    printf("Введите размерность матрицы:\n");
  }
}
 
