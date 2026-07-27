class Solution {
public:
    vector<bool> mrow;
    vector<bool> diag1;
    vector<bool> diag2;
    int count = 0;
    void fully_initialize(int n) {
        for (int i = 0; i < 2*n-1; i++) {
            diag1.push_back(false);
            diag2.push_back(false);
        }
        for (int i = 0; i < n; i++) {
            mrow.push_back(false);
        }
        return;
    }
    bool is_there_a_problem(int row, int col, int n) {
        // int A = (n - 1) - (row - col);
        // int B = (row + col);
        // int C = row;
        if (diag1[(n - 1) - (row - col)] == true) return true;
        if ((diag2[(row + col)] == true)) return true;
        if (mrow[row] == true) return true;
        return false;
    }
    void found_solution(int col,int n) {
        if (col==n) {
            count++;
            return;
        }
        for (int row = 0; row < n; row++) {
            if (is_there_a_problem(row,col,n)) {
                continue;
            }
            else {
                diag1[(n - 1) - (row - col)] = true;
                diag2[(row + col)] = true;
                mrow[row] = true;
                found_solution(col+1,n);
                diag1[(n - 1) - (row - col)] = false;
                diag2[(row + col)] = false;
                mrow[row] = false;
            }
        }
        return;
    }
    int totalNQueens(int n) {
        fully_initialize(n);
        found_solution(0, n);
        return count;
    }
};

// No Optimisation in is_there_a_problem

// class Solution {
// public:
//     vector<vector<string>> solutions;
//     vector<string> solution;
//     void fully_initialize(int n) {
//         for (int i = 0; i < n; i++) {
//             string s(n, '.');
//             solution.push_back(s);
//         }
//         return;
//     }
//     bool is_there_a_problem(int row, int col, int n) {
//         if (solution[row].find('Q') != string::npos) {
//             return true;
//         }
//         int temp_row = row-1;
//         int temp_col = col-1;
//         while (temp_row>-1&&temp_col>-1) {
//             if (solution[temp_row][temp_col] == 'Q') {
//                 return true;
//             }
//             temp_row--;
//             temp_col--;
//         }
//         temp_row = row+1;
//         temp_col = col-1;
//         while (temp_row<n&&temp_col>-1) {
//             if (solution[temp_row][temp_col] == 'Q') {
//                 return true;
//             }
//             temp_row++;
//             temp_col--;
//         }
//         return false;
//     }
//     void found_solution(int COL,int n) {
//         if (COL==n) {
//             solutions.push_back(solution);
//             return;
//         }
//         for (int ROW = 0; ROW < n; ROW++) {
//             if (is_there_a_problem(ROW,COL,n)) {
//                 continue;
//             }
//             else {
//                 solution[ROW][COL] = 'Q';
//                 found_solution(COL+1,n);
//                 solution[ROW][COL] = '.';
//             }
//         }
//         return;
//     }
//     int totalNQueens(int n) {
//         fully_initialize(n);
//         found_solution(0, n);
//         return solutions.size();
//     }
// };
