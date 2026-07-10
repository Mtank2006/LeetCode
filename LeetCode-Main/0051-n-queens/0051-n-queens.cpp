class Solution {
public:
    vector<vector<string>> solutions;
    vector<string> solution;
    void fully_initialize(int n) {
        for (int i = 0; i < n; i++) {
            string s(n, '.');
            solution.push_back(s);
        }
        return;
    }
    bool is_the_a_problem(int row, int col, int n) {
        if (solution[row].find('Q') != string::npos) {
            return true;
        }
        bool diagonal_problem = false;
        int temp_row = row-1;
        int temp_col = col-1;
        while (temp_row>-1&&temp_col>-1) {
            if (solution[temp_row][temp_col] == 'Q') {
                return true;
            }
            temp_row--;
            temp_col--;
        }
        temp_row = row+1;
        temp_col = col-1;
        while (temp_row<n&&temp_col>-1) {
            if (solution[temp_row][temp_col] == 'Q') {
                return true;
            }
            temp_row++;
            temp_col--;
        }
        return false;
    }
    void found_solution(int COL,int n) {
        if (COL==n) {
            solutions.push_back(solution);
            return;
        }
        for (int ROW = 0; ROW < n; ROW++) {
            if (is_the_a_problem(ROW,COL,n)) {
                continue;
            }
            else {
                solution[ROW][COL] = 'Q';
                found_solution(COL+1,n);
                solution[ROW][COL] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        fully_initialize(n);
        found_solution(0, n);
        return solutions;
    }
};
