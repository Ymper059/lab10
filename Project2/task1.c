#include <stdio.h>
#include <math.h>
#include <locale.h>

double f1(double x) {
    
    if (x <= 3.0) {
        return x * x - 3.0 * x + 9.0;
    }
    else {
        return 1.0 / (x * x * x + 3.0);
    }
}
double f2(double x) {
    return x * exp(sin(x * x));
}
int main() {
    setlocale(LC_CTYPE, "RUS");
    double x;
    int choice;
    printf("Введите значение x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Ошибка ввода.\n");
        return 1;
    }
    printf("\nВыберите действие:\n");
    printf("1 - Вычислить F1(x)\n");
    printf("2 - Вычислить F2(x)\n");
    printf("3 - Вычислить произведение F1(x) * F2(x)\n");
    printf("4 - Вычислить разность квадратов F1(x)^2 - F2(x)^2\n");
    printf("5 - Вычислить удвоенную сумму 2 * (F1(x) + F2(x))\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    double res1 = f1(x);
    double res2 = f2(x);

    switch (choice) {
    case 1:
        printf("F1(x) = %lf\n", res1);
        break;
    case 2:
        printf("F2(x) = %lf\n", res2);
        break;
    case 3:
        printf("Произведение: %lf\n", res1 * res2);
        break;
    case 4:
        printf("Разность квадратов: %lf\n", res1 * res1 - res2 * res2);
        break;
    case 5:
        printf("Удвоенная сумма: %lf\n", 2.0 * (res1 + res2));
        break;
    default:
        printf("Неверный выбор.\n");
    }

    return 0;
}