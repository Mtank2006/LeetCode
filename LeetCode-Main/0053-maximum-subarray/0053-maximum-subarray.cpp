class Solution {
public:
    // int Max = 0;
    // void backtrack(int right,vector<int>& nums) {
    //     if (right==-1) {
    //         return;
    //     }
    //     int tempMax = 0;
    //     for (int i = 0; i <= right; i++) {
    //         tempMax += nums[i];
    //     }
    //     Max = max(tempMax,Max);
    //     for (int i = 0; i <= right; i++) {
    //         tempMax -= nums[right];
    //         backtrack(right-1,nums);
    //         tempMax += nums[right];
    //     }
    // }
    // int maxSubArray(vector<int>& nums) {
    //     int size = nums.size();
    //     int left = 0;
    //     int right = size - 1;
    //     backtrack(right,nums);
    //     return Max;
    // }
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int Max = nums[0];
        int currentMax = Max;
        for (int i = 1; i < size; i++) {
            int temp = nums[i];
            currentMax = max(currentMax+nums[i],nums[i]);
            Max = max(currentMax,Max);
        }
        return Max;
    }
};
