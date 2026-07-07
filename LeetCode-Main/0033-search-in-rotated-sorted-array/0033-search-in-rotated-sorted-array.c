void split(int* nums, int start, int end,int target,int* index) {
    if (start > end || *index != -1) return;
    if (start==end) {
        if (nums[start]==target)
            *index = start;
            return;
    }
    int mid = start + (end-start)/2;
    split(nums,start,mid,target,index);
    split(nums,mid+1,end,target,index);
}
int search(int* nums, int numsSize, int target) {
    int index = -1;
    split(nums,0,numsSize-1,target,&index);
    return index;
}
