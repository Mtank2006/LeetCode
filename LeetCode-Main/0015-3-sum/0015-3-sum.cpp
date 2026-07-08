class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> set_of_array;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (( i > 0) && (nums[i] == nums[i-1])) {
                continue;
            }
            // first it was made by set ungiue property (then copying set to vector )and n3 test
            // for (int j = i + 1; j < nums.size() - 1; j++) {
            //     for (int k = j + 1; k < nums.size(); k ++) {
            //         if ((nums[i]+nums[j]+nums[k]) == 0) {
            //             set_of_array.push_back({nums[i],nums[j],nums[k]});
            //         }
            //     }
            // }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if ((nums[i]+nums[left]+nums[right]) < 0) {
                    left++;
                }
                else if ((nums[i]+nums[left]+nums[right]) > 0) {
                    right--;
                }
                else {
                    set_of_array.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    while ((left < right) && (nums[left - 1] == nums[left])) {
                        left++;
                    }
                    right--;
                    while ((left < right) && (nums[right + 1] == nums[right])) {
                        right --;
                    }
                }
            }
        }
        return set_of_array;
    }
};
