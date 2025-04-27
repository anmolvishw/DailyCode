#include <stdio.h>

void addition(int a[2][2], int b[2][2]) {
    int sum[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("Addition of two matrices:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

void multiple(int a[2][2], int b[2][2]) {
    int product[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            product[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Multiplication of two matrices:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    
    addition(a, b);
    multiple(a, b);

    return 0;
}
