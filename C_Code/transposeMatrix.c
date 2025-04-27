#include <stdio.h>

int main() {
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int transpose[3][2];


    printf("Before Transpose of the matrix\n");
    for(int i=0;i<2;i++) {
        for(int j=0;j<3;j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0;i<2;i++) {
        for(int j=0;j<3;j++) {
            transpose[j][i] = a[i][j];
        }
    }

    printf("After Transpose of the matrix:\n");
    for(int i=0;i<3;i++) {
        for(int j=0;j<2;j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
