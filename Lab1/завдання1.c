#include <stdio.h>

void calculate_y(double x) {
    if ((x >= -49.0 && x <= -10.0) || (x > 0.0 && x <= 10.0)) {
        double y = 10.0 * x * x * x + (7.0 * x) / 5.0 + 2.0;
        printf("For x = %.2f, y = %.4f\n", x, y);
    } else {
        printf("For x = %.2f: Function undefined\n", x);
    }
}

int main() {
    calculate_y(6.8);
    calculate_y(7.6);
    calculate_y(-6.0);
    calculate_y(-7.0);

    return 0;
}