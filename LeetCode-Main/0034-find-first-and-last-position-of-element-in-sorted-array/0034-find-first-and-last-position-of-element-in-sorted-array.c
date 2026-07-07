void split(int* nums, int start, int end,int target,int* position) {
    if (start > end) return;
    if (start==end) {
        if (nums[start]==target){
            if (position[0]==-1) {
                position[0] = start;
                position[1] = start;
            }
            else if (start < position[0]) {
                position[0] = start;
            }
            else if (start > position[1]) {
                position[1] = start;
            }
        }
        return;
    }
    int mid = start + (end-start)/2;
    split(nums,start,mid,target,position);
    split(nums,mid+1,end,target,position);
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* position = (int*)malloc(2*sizeof(int));
    position[0] = -1;
    position[1] = -1;
    *returnSize = 2;
    split(nums,0,numsSize-1,target,position);
    return position;
}
