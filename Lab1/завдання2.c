#include <stdio.h>

int main(void) {
    float x;
    float y;

    printf("x: ");
    if (scanf("%f", &x) != 1) {
        printf("Error.\n");
        return 1;
    }

    if (x > 20.0f) {
        y = -x + 9.0f;
        printf("y(x) = %.2f\n", y);
    } else {
        printf("Function undefined.\n");
    }

    return 0;
}