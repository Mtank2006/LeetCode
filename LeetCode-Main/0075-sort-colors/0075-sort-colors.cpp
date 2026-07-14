// Dutch national flag algo
class Solution {
public:
    void sortColors(vector<int>& nums) {
    int l = 0, m = 0, h = nums.size() - 1;
        while(m<=h) {
            if (nums[m]==0) {
                swap(nums[m],nums[l]);
                l++;
                m++;
            }
            else if (nums[m] ==1) {
                m++;
            }
            else {
                swap(nums[m],nums[h]);
                h--;
            }
        }
    }
};

// Random k size sorter count.resize(size);


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int size = nums.size();
//         vector<int> count;
//         count.resize(3);
//         for (int i = 0; i < size; i++) {
//             count[nums[i]]++;
//         }
//         for (int i = 0; i < count[0]; i++) {
//             nums[i] = 0;
//         }
//         for (int i = 0; i < count[1]; i++) {
//             nums[i+count[0]] = 1;
//         }
//         for (int i = 0; i < count[2]; i++) {
//             nums[i+count[0]+count[1]] = 2;
//         }
//     }
// };
