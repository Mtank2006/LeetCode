class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        int closer;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (( i > 0) && (nums[i] == nums[i-1])) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                closer = (nums[i]+nums[left]+nums[right]);
                if (std::abs(target - closer) < std::abs(target - closest)) {
                    closest = closer;
                }
                if (closer < target) {
                    left++;
                    while ((left < right) && (nums[left - 1] == nums[left])) {
                        left++;
                    }
                }

                else if (closer > target) {
                    right--;
                    while ((left < right) && (nums[right + 1] == nums[right])) {
                        right --;
                    }
                }

                else {
                    closest = closer;
                    return closest;
                }
            }
        }
        return closest;
    }
};
