#include <stdio.h>

int main() {
    int n;
    long long operation = 0;
    double x = 1.0 / 3.0;
    operation++;

    printf("n: ");
    if (scanf("%d", &n) != 1 || n < 1);

    double S = 1.0;
    double T = x * x;
    operation++;
    S -= T;
    operation++;

    for (int i = 2; i <= n; i++) {
        double k = (-4.0 * x * x) / ((2 * i - 1) * (2 * i));
        operation += 6;

        T *= k;
        operation++;

        S -= T;
        operation++;
    }
    printf("S = %.15f\n", S);
    printf("Operations: %lld\n", operation);

    return 0;
}