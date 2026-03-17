#include <stdio.h>

void printSubarrays(int arr[], int n) {
    int sum;

    for (int i = 0; i < n; i++) {
        sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == 0) {
                printf("Subarray from index %d to %d: ", i, j);

                for (int k = i; k <= j; k++) {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }
        }
    }
}

int main() {
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printSubarrays(arr, n);

    return 0;
}