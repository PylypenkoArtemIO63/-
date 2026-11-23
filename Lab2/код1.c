#include <stdio.h>

int main() {
    int n;
    double x = 1.0 / 3.0;
    long long operation = 1;
    double sum = 0.0;

    printf("n: ");
    if (scanf("%d", &n));
    for (int i = 1; i <= n; i++) {
        double power = 1.0;
        double powerx = 1.0;
        double factorial = 1.0;

        int limit = 2 * i;
        operation++;

        for (int j = 1; j <= limit; j++) {
            factorial *= j;
            powerx *= x;
            operation += 2;

            if (j < limit) {
                power *= 2.0;
                operation++;
            }
        }
        double sign = (i + 1) % 2 == 0 ? 1.0 : -1.0;
        operation += 2;
        double term = (sign * power * powerx) / factorial;
        sum += term;
        operation += 4;
    }

    double result = 1.0 - sum;
    operation++;

    printf("\nS = %lf\n", result);
    printf("Operations: %lld\n", operation);
    return 0;
}