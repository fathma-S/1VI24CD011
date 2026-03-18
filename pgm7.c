#include <stdio.h>

int maxLenSubarray(int arr[], int n, int k) {
    int sum = 0, maxLen = 0;

    // Simple array to store prefix sums (for small range)
    int prefix[1000];
    int index[1000];
    int size = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum itself equals k
        if (sum == k) {
            maxLen = i + 1;
        }

        // Check if (sum - k) seen before
        for (int j = 0; j < size; j++) {
            if (prefix[j] == sum - k) {
                int len = i - index[j];
                if (len > maxLen)
                    maxLen = len;
            }
        }

        // Store prefix sum if not already present
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (prefix[j] == sum) {
                found = 1;
                break;
            }
        }

        if (!found) {
            prefix[size] = sum;
            index[size] = i;
            size++;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {10, 5, 2, 7, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 15;

    int result = maxLenSubarray(arr, n, k);

    printf("Maximum length subarray: %d\n", result);

    return 0;
}
