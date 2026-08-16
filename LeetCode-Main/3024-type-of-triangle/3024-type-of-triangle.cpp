class Solution {
public:
    string triangleType(vector<int>& nums) {

        if (nums[0] >= nums[1] + nums[2] || nums[1] >= nums[0] + nums[2] || nums[2] >= nums[0] + nums[1]) {
            return "none";
        }

        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
            return "isosceles";
        }

        return "scalene";
    }
};



// class Solution {
// public:
//     string triangleType(vector<int>& nums) {

//         // int sum_0_1 = nums[0] + nums[1];
//         // int sum_1_2 = nums[1] + nums[2];
//         // int sum_0_2 = nums[0] + nums[2];

//         vector<int> sums= {nums[1] + nums[2], nums[0] + nums[2], nums[0] + nums[1]};

//         for (int i = 0; i < 3; ++i) {
//             if (nums[i] >= sums[i]) {
//                 return "none";
//             }
//         }

//         int equals = 0;

//         for (int i = 0; i < 3; ++i) {
//             for (int j = i + 1; j < 3; ++j) {
//                 if (nums[i] == nums[j]) {
//                     equals++;
//                 }
//             }
//         }

//         if (equals == 0) {
//             return "scalene";
//         }
//         else if (equals == 1) {
//             return "isosceles";
//         }
//         return "equilateral";
//     }
// };
