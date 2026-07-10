class Solution {
public:
    // vector<vector<int>> output;
    // void swap_to_output(vector<vector<int>>& output, int left, int right, int i, vector<int>& nums, vector<int> current) {
    //     if (left == -1) {
    //         vector
    //         left = size - 1;
    //         int temp = current[right];
    //         current[right] = current[left];
    //         current[left] = temp;
    //     }

    //     // right = size - i - 1;
    //     // left = right - 1;
    //     // if (left == -1) {
    //     //     left = size -1;
    //     // }
    //     // i++;
    //     swap_to_output(output,left,right);
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     int size = nums.size();
    //     int left;
    //     int right;
    //     int i = 0;
    //     right = size - i - 1;
    //     left = right - 1;
    //     if (left == -1) {
    //         left = size -1;
    //     }

    //     swap_to_output(output,left,right,i,nums,nums);
    // }
    vector<vector<int>> output;
    // void swap_to_output(vector<vector<int>>& output, int left, int right, vector<int> current) {
    //     output.push_back(current);
    //     int temp = current[left];
    //     current[left] = current[right];
    //     current[right] = temp;
    //     output.push_back(current);
    //     return;
    // }
    void backtrack(vector<int>& current, int index) {
        int size = current.size();
        if (index == size) {
            output.push_back(current);
            return;
        }
        for (int i = index; i < size; i++) {
            swap(current[i],current[index]);
            backtrack(current,index+1);
            swap(current[i],current[index]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // int size = nums.size();
        // vector<int> current = nums;
        // if (size == 1) {
        //     output.push_back(nums);
        //     return output;
        // }
        // if (size == 2) {
        //     swap_to_output(output,size - 2,size - 1,current);
        //     return output;
        // }
        // for (int i = 0; i < size-2; i++) {
        //     for (int j = i; j < size; j++) {
        //         int temp = current[i];
        //         current[i] = current[j];
        //         current[j] = temp;
        //         swap_to_output(output,size - 2,size - 1,current);
        //     }
        // }
        // return output;
        // if (size == 1) {
        //     output.push_back(nums);
        //     return output;
        // }
        // if (size == 2) {
        //     swap_to_output(output,size - 2,size - 1,current);
        //     return output;
        // }
        backtrack(nums,0);
        return output;
    }
};
