#include <stdio.h>

int largestSubarray(int arr[], int n) {
    int max_len = 1;

    for (int i = 0; i < n; i++) {

        int min = arr[i], max = arr[i];

        // visited array to check duplicates
        int visited[1000] = {0};

        for (int j = i; j < n; j++) {

            // If duplicate found → break
            if (visited[arr[j]])
                break;

            visited[arr[j]] = 1;

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