#include <stdio.h>

int main() {
    int arr[10][10], n, i, j, sum = 0;

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Diagonal elements are:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i][i]);
        sum += arr[i][i];
    }

    printf("\nSum of diagonal elements = %d", sum);

    return 0;
}