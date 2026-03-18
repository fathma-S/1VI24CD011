#include <stdio.h>

// Function to sort arr2 (simple insertion sort)
void sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr1[], int arr2[], int n, int m) {
    for (int i = 0; i < n; i++) {

        // If current element of arr1 > first of arr2
        if (arr1[i] > arr2[0]) {

            // Swap
            int temp = arr1[i];
            arr1[i] = arr2[0];
            arr2[0] = temp;

            // Re-sort arr2
            sort(arr2, m);
        }
    }
}

int main() {
    int arr1[] = {1, 5, 9, 10, 15, 20};
    int arr2[] = {2, 3, 8, 13};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    merge(arr1, arr2, n, m);

    printf("arr1: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr1[i]);

    printf("\narr2: ");
    for(int i = 0; i < m; i++)
        printf("%d ", arr2[i]);

    return 0;
}