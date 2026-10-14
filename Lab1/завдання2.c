#include <stdio.h>

double calculate_y(double x) {
    double result;

    if (x > 20.0) {
        result = -x + 9.0;
    } else {
        printf("function undefined\n");
        result = 0.0;
    }

    return result;
}
int main() {
    double x = 0;
    double y = calculate_y(x);

    if (x > 20.0) {
        printf("For x = %.2f, y = %.2f\n", x, y);
    }

    return 0;
}