/*
Астахова Анастасия Сергеевна, группа М8О-113Б-22
Второй вариант.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b) {
	return (a>b) ? a : b;
}

int sign(int n) {
	return (n>0) ? 1 : -1;
}

int modulo(int a, int b) {
	float temp = 1.0 * a / b;
	return a - (floor(temp) * b);
}

bool is_in_area(int x, int y, int r1, int r2, int i, int j) {
	if ( (sqrt( pow(i-x, 2) + pow(j-y, 2) ) >= r1) &&
	(sqrt( pow(i-x, 2) + pow(j-y, 2) ) <= r2) ) {
		return true;
	}
	else {
		return false;
	}
}

int count_i(int i, int j, int l, int k) {
	return abs(i-j+l) / (3-sign(i-j+k)) + 10;
}

int count_j(int i, int j, int l, int k) {
	return abs(i+j-l) / (3-sign(j-i+k)) + 10;
}

int count_l(int i, int j, int l, int k) {
	return modulo(max(i*j, j*l) * (k+1), 40);
}

int main() {
	int x, y, r1, r2;
	x = 10;
	y = 10;
	r1 = 5;
	r2 = 10;

	int i0 = 0, j0 = -3, l0 = -7;

	for (int k = 1; k <= 50; k++) {
		int i = count_i(i0, j0, l0, k);
		int j = count_j(i0, j0, l0, k);
		int l = count_l(i0, j0, l0, k);

		if (is_in_area(x, y, r1, r2, i, j)) {
			printf("YES %d\n", k);
			//printf("i = %d\n", i);
			//printf("j = %d\n", j);
			//printf("l = %d\n", l);
			return 0;
		}

		i0 = i;
		j0 = j;
		l0 = l;
	}

	printf("NO\n");
	printf("i = %d\n", i0);
	printf("j = %d\n", j0);
	printf("l = %d\n", l0);
	return 0;
}
