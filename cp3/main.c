#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>

int main()
{
    setlocale(LC_ALL, "Rus");

    double eps = 1.0;
    while (1.0 + eps / 2 > 1) {
        eps /= 2;
    }

    double A = 0.0;
    double B = 0.5;
    int n;
    double func;

    int steps;
    double step = 0.05;
    printf("Введите количество разбиений отрезка: ");
    scanf("%d", &steps);
    printf("\n");

    step = (B - A) / steps;

    printf("--------------------------------------------------------------------------------------------------");
    printf("\n|\tx\t|\tряд Тейлора          \t|\tзначение функции     \t| число итераций |\n");
    printf("--------------------------------------------------------------------------------------------------");

    bool flag = false;

    for (double x = A; x <= B; x+=step) {
        double elem, sum_elem = 0;
        n = 1;
        do { 
            elem = pow(x, n) / n;
            sum_elem += 2 * elem;
            n+=2;
        } while (fabs(elem) > eps && n <= 100);

        func = log((1 + x) / (1 - x));

        printf("\n|\t%.2f\t|\t%.18f\t|\t%.18f\t|\t%d\t|", x, sum_elem, func, n);
        if (x + step > B && x != B) {
            flag = true;
        }
    }

    if (flag) {
        double elem, sum_elem = 0;
        n = 1;
        do {
            elem = pow(B, n) / n;
            sum_elem += 2 * elem;
            n += 2;
        } while (fabs(elem) > eps && n <= 100);

        func = log((1 + B) / (1 - B));

        printf("\n|\t%.2f\t|\t%.18f\t|\t%.18f\t|\t%d\t|", B, sum_elem, func, n);
    }
    return 0;
}
