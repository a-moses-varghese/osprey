#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

  // Step 1: Sort the array
  qsort(nums, numsSize, sizeof(int), compare);

  // Allocate memory for result
  int** result = (int**)malloc(sizeof(int*) * numsSize * numsSize); // Maximum possible size
  *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
  *returnSize = 0;

  // Step 2: Loop through the array
  for (int i = 0; i < numsSize - 2; i++) {
    // Skip duplicates for the first element
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    int left = i + 1;
    int right = numsSize - 1;

    // Step 3: Two-pointer approach
    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];
      if (sum == 0) {
        // Found a valid triplet
        int* triplet = (int*)malloc(sizeof(int) * 3);
        triplet[0] = nums[i];
        triplet[1] = nums[left];
        triplet[2] = nums[right];
        result[*returnSize] = triplet;
        (*returnColumnSizes)[*returnSize] = 3;
        (*returnSize)++;

        // Skip duplicates for left and right
        while (left < right && nums[left] == nums[left + 1]) left++;
        while (left < right && nums[right] == nums[right - 1]) right--;

        left++;
        right--;
      } else if (sum < 0) {
        left++;  // Move left pointer right to increase sum
      } else {
        right--; // Move right pointer left to decrease sum
      }
    }
  }

  return result;
}

int main() {
  int nums[] = {-1, 0, 1, 2, -1, -4};
  int numsSize = sizeof(nums) / sizeof(nums[0]);

  int returnSize;
  int* returnColumnSizes;

  int** result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

  // Print the results
  printf("Found %d triplets:\n", returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("[%d, %d, %d]\n", result[i][0], result[i][1], result[i][2]);
    free(result[i]); // Free each triplet
  }
  free(result); // Free result array
  free(returnColumnSizes); // Free column sizes array

  return 0;
}
