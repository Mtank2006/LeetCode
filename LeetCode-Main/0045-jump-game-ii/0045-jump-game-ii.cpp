class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int jumps = 0;
        int left = 0;
        int right = 0;
        if (size == 1) {
            return 0;
        }
        while (left <= right) {
            int farthest = 0;
            for (int i = left; i <= right; i++) {
                if (i + nums[i] >= size - 1) {
                    return jumps+1;
                }
                if (i + nums[i] > farthest) {
                    farthest = i + nums[i];
                }
            }
            left = right + 1;
            right = farthest;
            jumps++;
        }
        return jumps;
        // for (int i = 0; i < size; i++) {
        //     int skips_remains = nums[i];
        //     int max = skips_remains;
        //     int max_index = i;
        //     for (int  j = i + 1; j < nums[i]; j++) {
        //         skips_remains--;
        //         if ((nums)&&(nums[j] > skips_remains)) {
        //             max = nums[j];
        //             max_index = j;
        //         }
        //     }
        // }
    }
};
