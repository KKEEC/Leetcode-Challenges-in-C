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