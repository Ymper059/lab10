#include <stdio.h>
#include <math.h>
#include <locale.h>
#define PI 3.14159265358979323846
double arccos_n(double x, int N) {
    double sum = PI / 2.0 - x;
    double term = x; 
    double numerator = 1.0;
    double denominator = 2.0;
    for (int n = 1; n < N; n++) {
        numerator *= (2.0 * n - 1.0);
        denominator *= (2.0 * n);
        double coeff = numerator / denominator;
        double power = pow(x, 2 * n + 1);
        term = coeff * power / (2.0 * n + 1.0);
        sum -= term;
    }
    return sum;
}

double arccos_eps(double x, double eps) {
    double sum = PI / 2.0 - x;

    double term = x;
    double numerator = 1.0;
    double denominator = 2.0;

    int n = 1;
    do {
        numerator *= (2.0 * n - 1.0);
        denominator *= (2.0 * n);

        double coeff = numerator / denominator;
        double power = pow(x, 2 * n + 1);

        term = coeff * power / (2.0 * n + 1.0);
        sum -= term;

        n++;
    } while (fabs(term) > eps);

    return sum;
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    double x;
    printf("Введите значение x (|x| < 1): ");
    if (scanf("%lf", &x) != 1 || fabs(x) >= 1.0) {
        printf("Ошибка: |x| должно быть меньше 1.\n");
        return 1;
    }
    double standard_val = acos(x);
    printf("\n1. Стандартная функция acos(%lf) = %.6lf\n", x, standard_val);
    printf("\n2. Таблица сравнения (N членов ряда):\n");
    printf("--------------------------------------------------\n");
    printf("| %-3s | %-12s | %-16s |\n", "N", "arccos_N", "Отклонение");
    printf("--------------------------------------------------\n");

    for (int n = 1; n <= 15; n++) {
        double calc_val = arccos_n(x, n);
        double deviation = calc_val - standard_val;
        printf("| %-3d | %-12.6lf | %+-16.6e |\n", n, calc_val, deviation);
    }
    printf("--------------------------------------------------\n");
    double eps = 0.0001; 
    double calc_eps_val = arccos_eps(x, eps);
    printf("\n3. Вычисление с точностью eps = %g:\n", eps);
    printf("Значение через ряд: %.6lf\n", calc_eps_val);
    printf("Отклонение от стандартной: %.6e\n", calc_eps_val - standard_val);
    return 0;

}
