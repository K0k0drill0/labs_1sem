#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>

#define _CRT_SECURE_NO_WARNINGS

double f1(double x) {
    return exp(x) + log(x) - 10 * x;
}

double f2(double x) {
    return cos(x) - exp(-(x * x / 2)) + x - 1;
}

double f1_iter(double x) {
    return x - 1.0/20.0 * f1(x);
}

double f2_iter(double x) {
    return x - 1.0 * f2(x);
}

double derivative1(double x) {
    return exp(x) + 1.0 / x - 10;
}

double derivative2(double x) {
    return -sin(x) - exp(-(x * x / 2)) * (-x) + 1;
}

double dichotomy(double a, double b, double(*form)(double x), double eps)
{
    int count = 0;
    double x = 0.0;

    while (fabs(a - b) > eps) {
        count += 1;
        x = (a + b) / 2.0;

        if (form(a) * form(x) > 0) {
            a = x;
        }
        else {
            b = x;
        }
        if (count == 150) {
            break;
        }
    }
    return x;
}

double newton(double a, double b, double(*form)(double x), double(*derivative)(double x), double eps)
{
    int count = 0;
    double x_now = (a + b) / 2.0;
    double x_last = 0;

    while (fabs(x_now - x_last) > eps) {
        count += 1;
        x_last = x_now;
        x_now -= form(x_now) / derivative(x_now);
        if (count == 150) {
            break;
        }
    }

    return x_now;

}

double iteration(double a, double b, double(*iter_form)(double x), double eps)
{
    int count = 0;
    double x_now = (a + b) / 2.0;
    double x_last = 0.0;

    while (fabs(x_now - x_last) > eps) {
        count += 1;
        x_last = x_now;
        x_now = iter_form(x_now);
        if (count == 150) {
            break;
        }

    }
    return x_now;

}


int main()
{
    setlocale(LC_ALL, "Rus");
    double EPS = 1.0;
    while (1.0 + EPS / 2 > 1) {
        EPS /= 2;
    }

    printf("\t|--------------------------------------------------------------------------------------|\n");

    printf("\t|%20s| %20s| %20s| %21s\n", "Метод", "Дихотомии ", "Итераций ", "Ньютона |");

    printf("\t|--------------------------------------------------------------------------------------|\n");

    printf("\t|%20s| %20.16f| %20.16f| %20.16f|\n", "Вариант 1", dichotomy(3.0, 4.0, f1, EPS), iteration(3.0, 4.0, f1_iter, EPS), newton(3.0, 4.0, f1, derivative1, EPS));

    printf("\t|--------------------------------------------------------------------------------------|\n");

    printf("\t|%20s| %20.16f| %20.16f| %20.16f|\n", "Вариант 2", dichotomy(1.0, 2.0, f2, EPS), iteration(1.0, 2.0, f2_iter, EPS), newton(1.0, 2.0, f2, derivative2, EPS));

    printf("\t|--------------------------------------------------------------------------------------|\n");
    //printf("%f\n", EPS);

    return 0;

}
