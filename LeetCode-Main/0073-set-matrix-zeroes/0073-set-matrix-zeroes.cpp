class Solution {
public:
    vector<bool> rowToChange;
    vector<bool> colToChange;
    void get_the_zeros(vector<vector<int>>& matrix) {
        int n_row = matrix.size();
        int n_col = matrix[0].size();
        rowToChange.resize(n_row);
        colToChange.resize(n_col);
        for (int i = 0; i < n_row; i++) {
            for (int j = 0; j < n_col; j++) {
                if (matrix[i][j]==0) {
                    rowToChange[i] = true;
                    colToChange[j] = true;
                }
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        get_the_zeros(matrix);
        int n_row = matrix.size();
        int n_col = matrix[0].size();
        int r_size = rowToChange.size();
        for (int c = 0; c < n_col; c++) {
            if (colToChange[c]==true) {
                for (int i = 0; i < n_row; i++) {
                    matrix[i][c] = 0;
                }
            }
        }
        for (int r = 0; r < n_row; r++) {
            if (rowToChange[r]==true) {
                for (int i = 0; i < n_col; i++) {
                    matrix[r][i] = 0;
                }
            }
        }
    }
};


//By set

// class Solution {
// public:
//     set<int> rowToChange;
//     set<int> colToChange;
//     void get_the_zeros(vector<vector<int>>& matrix) {
//         int n_row = matrix.size();
//         int n_col = matrix[0].size();
//         for (int i = 0; i < n_row; i++) {
//             for (int j = 0; j < n_col; j++) {
//                 if (matrix[i][j]==0) {
//                     // whereAreZeros.push_back({i, j});
//                     rowToChange.insert(i);
//                     colToChange.insert(j);
//                 }
//             }
//         }
//     }
//     void setZeroes(vector<vector<int>>& matrix) {
//         get_the_zeros(matrix);
//         int n_row = matrix.size();
//         int n_col = matrix[0].size();
//         int r_size = rowToChange.size();
//         for (int c : colToChange) {
//             for (int i = 0; i < n_row; i++) {
//                 matrix[i][c] = 0;
//             }
//         }
//         for (int r : rowToChange) {
//             for (int i = 0; i < n_col; i++) {
//                 matrix[r][i] = 0;
//             }
//         }
//     }
// };



// by 2*(m*n) vector to store initial zeros coordinates



// class Solution {
// public:
//     vector<vector<int>> whereAreZeros;
//     void get_the_zeros(vector<vector<int>>& matrix) {
//         int n_row = matrix.size();
//         int n_col = matrix[0].size();
//         for (int i = 0; i < n_row; i++) {
//             for (int j = 0; j < n_col; j++) {
//                 if (matrix[i][j]==0) {
//                     whereAreZeros.push_back({i, j});
//                 }
//             }
//         }
//         // for (int i = 0; i < whereAreZeros.size(); i++) {
//         //         cout << whereAreZeros[i][0] << " " << whereAreZeros[i][1] ;
//         //     cout << "\n";
//         // }
//     }
//     void setZeroes(vector<vector<int>>& matrix) {
//         get_the_zeros(matrix);
//         int n_row = matrix.size();
//         int n_col = matrix[0].size();
//         for (int i = 0; i < whereAreZeros.size(); i++) {
//             for (int c = 0; c < n_col; c++) {
//                 matrix[whereAreZeros[i][0]][c] = 0;
//             }
//             for (int r = 0; r < n_row; r++) {
//                 matrix[r][whereAreZeros[i][1]] = 0;
//             }
//         }
//     }
// };
