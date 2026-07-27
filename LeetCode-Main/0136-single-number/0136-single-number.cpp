// With XOR operator


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        int number = 0;
        for (int i = 0; i < size; i ++) {
            number = number ^ nums[i];
        }
        return number;
    }
};


// Optimised Form


// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int size = nums.size();
//         int number;
//         for (int i = 0; i < size; i ++) {
//             bool found = true;
//             int value = nums[i];
//             for (int j = 0; j < size; j++) {
//                 if (i == j) {
//                     continue;
//                 }
//                 else {
//                     if (nums[j] == value) {
//                         found = false;
//                         break;
//                     }
//                 }
//             }
//             if (found == true) {
//                 number = value;
//                 break;
//             }
//         }
//         return number;
//     }
// };


// No Optimisation


// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int size = nums.size();
//         unordered_map<int, int> visited;
//         for (int  i = 0; i < size; i++) {
//             if (visited.find(nums[i]) == visited.end()) {
//                 visited[nums[i]] = 1;
//             }
//             else {
//                 visited[nums[i]]++;
//             }
//         }
//         int value;
//         for (const auto& pair : visited) {
//             if (pair.second == 1) {
//                 value = pair.first;
//                 break;
//             }
//         }
//         return value;
//     }
// };
