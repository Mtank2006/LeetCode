class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nr = matrix.size();
        int nc = matrix[0].size();
        if (target < matrix[0][0]) {
            return false;
        }
        if (nr == 1) {
            return binary_search(matrix[0].begin(),matrix[0].end(), target);
        }
        int left = 0;
        int right = nr - 1;
        while (left<=right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] == target) {
                return true;
            }
            else if (matrix[mid][0] < target) {
                left = mid + 1 ;
            }
            else {
                right = mid - 1;
            }
        }
        return binary_search(matrix[left-1].begin(),matrix[left-1].end(), target);
    }
};


// Linear on to find row then binary

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int nr = matrix.size();
//         int nc = matrix[0].size();
//         int getr = 0;
//         for (int i = 0; i < nr; i++) {
//             if (matrix[i][0] > target) {
//                 break;
//             }
//             getr = i;
//         }
//         return binary_search(matrix[getr].begin(),matrix[getr].end(), target);
//     }
// };

// Linear on to find row then linear to get the result

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int nr = matrix.size();
//         int nc = matrix[0].size();
//         int getr = 0;
//         for (int i = 0; i < nr; i++) {
//             if (matrix[i][0] > target) {
//                 break;
//             }
//             getr = i;
//         }
//         // cout << getr ;
//         for (int i = 0; i < nc; i++) {
//             if (matrix[getr][i] == target) {
//                 return true;
//             }
//         }
//     return false;
//     }
// };
