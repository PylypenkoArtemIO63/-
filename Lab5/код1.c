#include <stdio.h>

#define M 7
#define N 7

int main() {
    int A[M][N];

    printf("Enter the elements of matrix %dx%d:\n", M, N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", A[i][j]);
        }
        printf("\n");
    }

    int sort;
    do {
        sort = 0;
        for (int j = 0; j + 2 < N; j += 2) {
            if (A[0][j] > A[0][j + 2]) {
                int temp = A[0][j];
                A[0][j] = A[0][j + 2];
                A[0][j + 2] = temp;

                sort = 1;
            }
        }
    } while (sort);
    printf("\nSorted matrix:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}