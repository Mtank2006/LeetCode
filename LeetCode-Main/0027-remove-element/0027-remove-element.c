int removeElement(int* nums, int numsSize, int val) {
    int left =0;
    int right = numsSize-1;
    while (right >= left) {
        if (nums[left]==val) {
            nums[left] = nums[right];
            right--;
        }
        else {
            left ++;
        }
    }
    return left;
}
