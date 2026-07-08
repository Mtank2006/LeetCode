class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     sort(nums.begin(), nums.end());
    //     std::vector<std::vector<int>> set_of_array;
    //     int left_start = 0;
    //     int right_end = nums_size -1;
    //     while (left_start < right_end - 2) {
    //         if (( left_start > 0) && (nums[left_start] == nums[left_start-1])) {
    //             left_start++;
    //             continue;
    //         }
    //         if (( right_end < nums_size -1) && (nums[right_end] == nums[right_end+1])) {
    //             right_end--;
    //             continue;
    //         }
    //         int left = left_start + 1;
    //         int right = right_end - 1;
    //         while (left < right) {
    //             if ((nums[left_start]+nums[right_end]+nums[left]+nums[right]) < target) {
    //                 left++;
    //             }
    //             else if ((nums[left_start]+nums[right_end]+nums[left]+nums[right]) > target) {
    //                 right--;
    //             }
    //             else {
    //                 set_of_array.push_back({nums[left_start],nums[left],nums[right],nums[right_end]});
    //                 left++;
    //                 while ((left < right) && (nums[left - 1] == nums[left])) {
    //                     left++;
    //                 }
    //                 right--;
    //                 while ((left < right) && (nums[right + 1] == nums[right])) {
    //                     right --;
    //                 }
    //             }
    //         }
    //         if (abs(nums[left_start]) > abs(nums[right_end])) {
    //             left_start++;
    //         }
    //         else {
    //             right_end--;
    //         }
    //     }
    //     return set_of_array;



        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> set_of_array;
        int nums_size = nums.size();
        for (int j = 0; j < nums_size - 3; j++) {
            if (( j > 0) && (nums[j] == nums[j-1])) {
                    continue;
                }
            for (int i = j+1; i < nums_size - 2; i++) {
                if (( i > (j+1)) && (nums[i] == nums[i-1])) {
                    continue;
                }
                int left = i + 1;
                int right = nums_size - 1;
                while (left < right) {
                    long long sum = (long long)nums[j] + nums[i] + nums[left] + nums[right];
                    if (sum < target) {
                        left++;
                    }
                    else if (sum > target) {
                        right--;
                    }
                    else {
                        set_of_array.push_back({nums[j],nums[i],nums[left],nums[right]});
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
        }
        return set_of_array;
    }
};
