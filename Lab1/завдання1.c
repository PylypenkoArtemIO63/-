#include <stdio.h>

int main() {
    float x;

    printf("x: ");
    if (scanf("%f", &x) == 1) {
        if ((x >= -49.0f && x <= -10.0f) || (x > 0.0f && x <= 10.0f)) {
            float y = 10.0f * x * x * x + (7.0f * x) / 5.0f + 2.0f;
            printf("y(x) = %.4f\n", y);
        } else {
            printf("Function undefined\n");
        }
    } else {
        printf("Error\n");
    }

    return 0;
}