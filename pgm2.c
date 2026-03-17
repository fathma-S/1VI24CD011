#include <stdio.h>

int subArrayExists(int arr[], int n) {
    int sum = 0;

    // Simple array to store prefix sums (for small inputs)
    int prefix[1000];
    int size = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum becomes 0 OR element itself is 0
        if (sum == 0 || arr[i] == 0)
            return 1;

        // Check if sum already exists
        for (int j = 0; j < size; j++) {
            if (prefix[j] == sum)
                return 1;
        }

        // Store prefix sum
        prefix[size++] = sum;
    }

    return 0;
}

int main() {
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (subArrayExists(arr, n))
        printf("Subarray with 0 sum exists\n");
    else
        printf("No such subarray exists\n");

    return 0;
}