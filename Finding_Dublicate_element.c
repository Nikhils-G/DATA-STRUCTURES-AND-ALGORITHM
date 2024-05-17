#include <stdio.h>
#include <stdbool.h>

// Function to check if the array contains any duplicate values
bool containsDuplicate(int* nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};  // Example array
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    if (containsDuplicate(nums, numsSize)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
