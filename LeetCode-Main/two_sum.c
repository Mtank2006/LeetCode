#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i =0;i<numsSize-1;i++){
        for (int j=i+1;j<numsSize;j++) {
            if (nums[i]+nums[j]==target) {
                result[0]=i;
                result[1]=j;
                goto end;
            }
        }
    }
    end:
    return result;
}
int main () {
    int numsSize,temp,target,returnSize;
    scanf ("%d",&numsSize);     
    int nums[numsSize];
    for (int i =0;i<numsSize;i++) {
        scanf ("%d",&temp);
        nums[i]=temp;
    }
    scanf ("%d",&target);
    int* sum = twoSum(nums,numsSize,target,&returnSize);
    printf ("[%d, %d]\n", sum[0], sum[1]);
}