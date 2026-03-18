#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Store prefix sums and their first index
    int prefix[2000];
    int index[2000];
    int size = 0;

    for (int i = 0; i < n; i++) {

        // Convert 0 to -1
        if (arr[i] == 0)
            sum += -1;
        else
            sum += 1;

        // Case 1: sum becomes 0
        if (sum == 0)
            maxLen = i + 1;

        // Check if sum already exists
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (prefix[j] == sum) {
                int len = i - index[j];
                if (len > maxLen)
                    maxLen = len;
                found = 1;
                break;
            }
        }

        // Store first occurrence
        if (!found) {
            prefix[size] = sum;
            index[size] = i;
            size++;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {0, 0, 1, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxLen(arr, n);

    printf("Maximum length: %d\n", result);

    return 0;
}