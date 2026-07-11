class Solution {
public:
    vector<int> output;
    void box(vector<vector<int>>& matrix, int level,int n_row, int n_col) {
        int top = level;
        int bottom = n_row-1-level;
        int left = level;
        int right = n_col - 1 - level;
        if (top>bottom||(left>right)) {
            return;
        }
        for (int i = top; i <= right; i++) {
            output.push_back(matrix[top][i]);
        }
        if (top < bottom) {
            for (int i = top+1; i <= bottom; i++) {
                output.push_back(matrix[i][right]);
            }
        }
        if (top < bottom) {
            for (int i = right-1; i >= top; i--) {
                output.push_back(matrix[bottom][i]);
            }
        }
        if (left<right) {
            for (int i = bottom-1; i >= top+1; i--) {
                output.push_back(matrix[i][left]);
            }
        }
        box(matrix,level+1,n_row,n_col);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n_row = matrix.size();
        int n_col = matrix[0].size();
        box(matrix,0,n_row,n_col);
        return output;
    }
};
        // for (int i = level; i < n_col-level; i++) {
        //     output.push_back(matrix[level][i]);
        // }
        // if (left < right) {
        //     for (int i = level+1; i < n_row-level; i++) {
        //         output.push_back(matrix[i][n_col-1-level]);
        //     }
        // }
        // if (top < bottom) {
        //     for (int i = n_col-1-1-level; i >= level; i--) {
        //         output.push_back(matrix[n_row-1-level][i]);
        //     }
        // }
        // if (left<right) {
        //     for (int i = n_row-1-1-level; i >= level+1; i--) {
        //         output.push_back(matrix[i][level]);
        //     }
        // }


        // if ((level==(n_row-level)/2)&&(level>(n_col-level)/2)) {
        //     for (int i = level; i < n_col-level; i++) {
        //     output.push_back(matrix[level][i]);
        //     }
        //     return;
        // }
        // if ((level==(n_col-level)/2)&&(level>(n_row-level)/2)) {
        //     for (int i = level; i < n_row-level; i++) {
        //     output.push_back(matrix[i][n_col-level-1]);
        //     }
        //     return;
        // }




        // if (level -1 >= n_row/2 && level -1 >= n_col/2) {
        //     if (level-1 == n_col/2) {
        //         for (int i = level; i < n_col-level; i++) {
        //             output.push_back(matrix[level][i]);
        //         }
        //     }
        //     else if (level-1 == n_row/2) {
        //         for (int i = level+1; i < n_row-level; i++) {
        //             output.push_back(matrix[i][n_col-level-1]);
        //         }
        //     }
        //     return;
        // }
        // for (int i = level; i < n_col-level; i++) {
        //     output.push_back(matrix[level][i]);
        // }
        // for (int i = level+1; i < n_row-level; i++) {
        //     output.push_back(matrix[i][n_col-level-1]);
        // }
        // for (int i = n_col-1-1-level; i >= level; i--) {
        //     output.push_back(matrix[n_row-1-level][i]);
        // }
        // for (int i = n_row-level-1-1; i > level; i--) {
        //     output.push_back(matrix[i][level]);
        // }
        // box(matrix,level+1,n_row,n_col);
        // return;
        // if ((level==(n_row-level)/2)&&(level==(n_col-level)/2)) {
        //     output.push_back(matrix[level][level]);
        //     return;
        // }
