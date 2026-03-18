#include <stdio.h>

void merge(int arr1[], int arr2[], int m, int n) {
    int i = m - 1;        // last element of arr1
    int j = n - 1;        // last element of arr2
    int k = m + n - 1;    // last position of arr1

    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k--] = arr1[i--];
        } else {
            arr1[k--] = arr2[j--];
        }
    }

    // Copy remaining elements of arr2
    while (j >= 0) {
        arr1[k--] = arr2[j--];
    }
}

int main() {
    int arr1[6] = {1, 3, 5, 0, 0, 0};
    int arr2[] = {2, 4, 6};

    int m = 3, n = 3;

    merge(arr1, arr2, m, n);

    printf("Merged array: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", arr1[i]);
    }

    return 0;
}