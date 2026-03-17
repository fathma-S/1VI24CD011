#include <stdio.h>

int largestSubarray(int arr[], int n) {
    int max_len = 1;

    for (int i = 0; i < n - 1; i++) {
        int min = arr[i], max = arr[i];

        for (int j = i + 1; j < n; j++) {

            // Check duplicate
            for (int k = i; k < j; k++) {
                if (arr[k] == arr[j])
                    goto next;
            }

            // Update min and max
            if (arr[j] < min) min = arr[j];
            if (arr[j] > max) max = arr[j];

            // Check condition
            if (max - min == j - i) {
                int len = j - i + 1;
                if (len > max_len)
                    max_len = len;
            }
        }
        next: ;
    }

    return max_len;
}

int main() {
    int arr[] = {10, 12, 11, 14, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = largestSubarray(arr, n);

    printf("Length of largest subarray: %d\n", result);

    return 0;
}