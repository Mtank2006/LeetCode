class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int jumps = nums[0];
        if (size==1) {
            return true;
        }
        for (int i = 0; i < size; i++) {
            if (jumps == 0) {
                return false;
            }
            if (jumps > size - i - 1) {
                return true;
            }
            jumps--;
            jumps = max(jumps,nums[i]);
        }
        return true;
    }
};
