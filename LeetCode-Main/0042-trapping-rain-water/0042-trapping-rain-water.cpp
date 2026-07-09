class Solution {
public:
    // void split_merge(vector<int>& height, int left, int right) {
    //     while(left<right) {
    //         int minimum = min(height[left],height[right]);
    //         for(int i = left; i < right; i++) {
    //             if (height[i] < minimum) {
    //                 height[i] = minimum;
    //             }
    //         }
    //         while (left < right && height[left] == height[left+1])  left++;
    //         while (left < right && height[right] == height[right-1])right--;
    //         if (height[left+1] > height[right-1]) {
    //             left++;
    //         }
    //         else {
    //             right--;
    //         }
    //     }
    //     return;
    // }
    // void split_fill(vector<int>& height, int left, int right) {
    //     if (left>=right) {
    //         return;
    //     }
    //     int start = left;
    //     int end = right;
    //     while(left<right) {
    //         int minimum = min(height[left],height[right]);
    //         for(int i = left; i < right; i++) {
    //             if (height[i] < minimum) {
    //                 height[i] = minimum;
    //             }
    //         }
    //         while (left < right && height[left] == height[left+1])  left++;
    //         while (left < right && height[right] == height[right-1])right--;
    //         if (height[left+1] > height[right-1]) {
    //             left++;
    //         }
    //         else {
    //             right--;
    //         }
    //     }
    //     int mid = start;
    //     for (int i = start; i < end; i++) {
    //         if (height[i]>height[mid]) mid = i;
    //     }
    //     split_fill(height,start,mid);
    //     split_fill(height,mid+1,end);
    //     split_merge(height,start,end);
    //     return;
    // }
    // int trap(vector<int>& height) {
    //     int initial_height = 0;
    //     int final_height = 0;
    //     int size = height.size();
    //     for (int i = 0; i < size; i++) {
    //         initial_height += height[i];
    //     }
    //     split_fill(height,0,size-1);
    //     for (int i = 0; i < size; i++) {
    //         final_height += height[i];
    //     }
    //     return final_height - initial_height;
    // }
    int trap(vector<int>& height) {
        int size = height.size();
        int water = 0;
        int left = 0;
        int right = size - 1;
        int leftMax = 0;
        int rightMax = 0;
        while (left<right) {
            if (height[left]>leftMax) {
                leftMax = height[left];
            }
            if(height[right]>rightMax) {
                rightMax = height[right];
            }
            if (leftMax > rightMax) {
                water += rightMax - height[right];
                right--;
            }
            else {
                water += leftMax - height[left];
                left++;
            }
        }
        return water;
    }
};
