#include <stdio.h>

void findPair(int arr[], int n, int target)
{
    int i, j;
    
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] + arr[j] == target)
            {
                printf("Pair found: %d and %d", arr[i], arr[j]);
                return;
            }
        }
    }
    
    printf("No pair found");
}

int main(void)
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int target = 16;
    int n = sizeof(arr) / sizeof(arr[0]);

    findPair(arr, n, target);

    return 0;
}