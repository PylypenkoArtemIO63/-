#include <stdio.h>
#include <math.h>

#define N 7
#define EPS 1e-6

int main() {
    double A[N][N];
    double target;

    printf("Enter the elements of matrix:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%8.2f ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nNumber in diagonal: ");
    scanf("%lf", &target);

    if (target < 0.0 || target > 5.0) {
        printf("Error.\n", target);
        return 1;
    }

    int left = 0;
    int right = N - 1;
    int found_row = -1;
    int found_col = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int r = N - 1 - mid;
        int c = mid;
        double val = A[r][c];

        if (fabs(val - target) < EPS) {
            found_row = r;
            found_col = c;
            break;
        } else if (val > target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found_row != -1) {
        printf("\nNumber %.2f exist\n", target);
        printf("Coordinates by 0: row = %d, column = %d\n", found_row, found_col);
        printf("Coordinates by 1: row = %d, column = %d\n", found_row + 1, found_col + 1);
    } else {
        printf("\nNumber %.2f is not exist.\n", target);
    }

    return 0;
}