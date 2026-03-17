#include <stdio.h>

int findDuplicate(int nums[], int n) {
    int slow = nums[0];
    int fast = nums[0];

    // Step 1: Detect cycle
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Step 2: Find duplicate (cycle start)
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    int nums[] = {1, 3, 4, 2, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    int duplicate = findDuplicate(nums, n);

    printf("Duplicate element: %d\n", duplicate);

    return 0;
}