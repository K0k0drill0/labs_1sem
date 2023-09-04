/*
Астахова Анастасия Сергеевна, группа М8О-113Б-22
Ошибка компиляции.
*/

#include <stdio.h>
int main() {
	float a, b;
	scanf("%f%f", &a, &b)
	
	if(a == 0) {
		printf("a не может быть равен нулю.\n");
		return 0;
	}
	
	float x = -b / a;
	printf("%f\n", x);
	return 0;
}
