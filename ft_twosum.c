#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i;
    int j;
    i = 0;
    j = 0;
    *returnSize = 2;
    int *result;
    while(i < numsSize - 1)
    {
        j = i + 1;
        while(j < numsSize)
        {
            if (nums[i] + nums[j] == target)
            {
                result = (int *)malloc(sizeof(int) * *returnSize);
                if (!result)
                    return(NULL);
                result[0] = i;
                result[1] = j;
                return (result);
            }
            j++;
        }
        i++;
    }
    *returnSize = 0;
    free(result);
    return (NULL);
}

int main() 
{
    int nums1[] = {2, 7, 11, 15}; 
    int nums2[] = {3, 2, 4}; 
    int nums3[] = {3, 3};
    int target1 = 9;
    int target2 = 6;
    int target3 = 6;
    int returnSize;

    // Test 1: Expected output: [0, 1]
    int* result1 = twoSum(nums1, sizeof(nums1) / sizeof(nums1[0]), target1, &returnSize);
    printf("Test 1 - Indices: [%d, %d]\n", result1[0], result1[1]);
    free(result1);

    // Test 2: Expected output: [1, 2]
    int* result2 = twoSum(nums2, sizeof(nums2) / sizeof(nums2[0]), target2, &returnSize);
    printf("Test 2 - Indices: [%d, %d]\n", result2[0], result2[1]);
    free(result2);

    // Test 3: Expected output: [0, 1]
    int* result3 = twoSum(nums3, sizeof(nums3) / sizeof(nums3[0]), target3, &returnSize);
    printf("Test 3 - Indices: [%d, %d]\n", result3[0], result3[1]);
    free(result3);   
    return 0;
}