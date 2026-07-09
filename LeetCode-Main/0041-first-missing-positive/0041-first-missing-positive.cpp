class Solution {
    public:
    // void swap_it(vector<int>& nums, int index, int size) {
    //     int temp = nums[index];
    //     if ((nums[index] != index + 1) && (nums[index] >= 0 ) && (index <size)) {
    //             nums[index] = nums[nums[index]-1];
    //             nums[index-1] = temp;
    //     }

    //     if ((nums[index] != index + 1) && (nums[index] >= 0)&&(index < size)) {
    //         swap_it(nums,index,size);
    //     }
    //     else if ((temp >= 0)&&(nums[temp] != temp + 1)&&(temp < size)) {
    //         swap_it(nums,temp,size);
    //     }
    //     return;
    // }
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int index = 0;
        while ((index < size)&&(nums[index] <= 0)) {
            index++;
        }
        int result = 1;
        for (int i = index; i < size; i++) {
            if ((result < nums[i])) {
                return result;
            }
            while (( i+1 < size)&&( nums[i] == nums[i+1])) {
                i++;
            }
            result++;
        }
        return result;
        // int size = nums.size();
        // for (int i = 0; i < size; i++) {
        //     int temp = nums[i];
        //     if (temp > 0 && temp < size) {
        //         nums[i] = nums[temp-1];
        //         nums[temp-1] = temp;
        //     }
        // }
        // int size = nums.size();
        // int left = 0;
        // int right = size;
        // while(left<right) {
        //     int vl = nums[left];
        //     int vr = nums[right];
        //     if (vl - 1 != left && vl - 1 >= 0) {
        //         int temp = nums[vl - 1];
        //         nums[vl - 1] = vl;
        //         nums[left] = temp;
        //         left++;
        //     }
        //     else if (vr - 1 != right && vr - 1 >= 0) {
        //         int temp = nums[vr - 1];
        //         nums[vr - 1] = vr;
        //         nums[right] = temp;
        //         right--;
        //     }
        // }

        // int size = nums.size();
        // for (int i = 0; i < size; i++) {

        // }
        // return result;

    }
};
