/*
Астахова Анастасия Сергеевна
группа М8О-113Б-22

Вариант 10
Выполнить циклический сдвиг влево десятичного представления числа
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int dig_amount(int n) {
  int ans = 1;
  while (n / 10 > 0) {
    n /= 10;
    ans++;
  }
  return ans;
}

int sign(int n) {
  if (n>0) {
    return 1;
  }
  else if (n < 0) {
    return -1;
  }
  else if (n == 0) {
    return 0;
  }
}

int power(int n, int m) {
  int ans = 1;
  for (int i = 0; i < m; i++) {
    ans *= n;
  }
  return ans;
}

int main() {
  //max int = 2147483647
  int inp;
  while (true) {
    printf("Введите число\n");
    scanf("%d", &inp);
    int znak = sign(inp);
    inp = abs(inp);
    int dig = dig_amount(inp);
    int p_ten = power(10, dig-1);

    if (inp % p_ten > 214748364) {
      printf("Ошибка. Число выйдет за рамки типа int.\n");
      continue;
    }

    int fir_digit = inp / p_ten;
    inp = inp % p_ten * 10 + fir_digit;

    printf("Ответ: %d\n", inp * znak);
  }
  return 0;
}
 
