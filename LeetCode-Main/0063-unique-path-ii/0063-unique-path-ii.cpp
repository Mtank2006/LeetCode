// Down to up dp traditional approach approach


class Solution {
public:
    vector<vector<long long>> cost;
    void fully_initialize_cost(int& n_col, int& n_row) {
        for (int i = 0; i <= n_row; i++) {
            vector<long long> temp;
            for (int j = 0; j <= n_col; j++) {
                temp.push_back(0);
            }
            cost.push_back(temp);
        }
        return;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n_row = obstacleGrid.size();
        int n_col = obstacleGrid[0].size();
        if (obstacleGrid[n_row-1][n_col-1] == 1) {
            return 0;
        }
        fully_initialize_cost(n_col,n_row);
        cost[n_row-1][n_col-1] = 1;
        for (int r = n_row-1; r >= 0; r--) {
            for (int c = n_col-1; c >= 0; c--) {
                if (obstacleGrid[r][c] == 1) {
                    cost[r][c] = 0;
                    continue;
                }
                if ((r==n_row-1)&&(c==n_col-1)) {
                    continue;
                }
                    cost[r][c] = cost[r+1][c] + cost[r][c+1];
                }
            }
        return cost[0][0];
    }
};



// Down to up dp mine approach


// class Solution {
// public:
//     vector<vector<long long>> cost;
//     void fully_initialize_cost(int& n_col, int& n_row) {
//         for (int i = 0; i < n_row; i++) {
//             vector<long long> temp;
//             for (int j = 0; j < n_col; j++) {
//                 temp.push_back(0);
//             }
//             cost.push_back(temp);
//         }
//         return;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n_row = obstacleGrid.size();
//         int n_col = obstacleGrid[0].size();
//         if (obstacleGrid[n_row-1][n_col-1] == 1) {
//             return 0;
//         }
//         fully_initialize_cost(n_col,n_row);
//         cost[n_row-1][n_col-1] = 1;
//         for (int r = n_row-1; r >= 0; r--) {
//             for (int c = n_col-1; c >= 0; c--) {
//                 if (obstacleGrid[r][c] == 1) {
//                     cost[r][c] = 0;
//                     continue;
//                 }
//                 if ((r + 1 < n_row)&&(c + 1 < n_col)) {
//                     cost[r][c] = cost[r+1][c] + cost[r][c+1];
//                 }
//                 else if ((r + 1 > n_row-1)&&(c + 1 <= n_col-1)) {
//                     cost[r][c] = cost[r][c+1];
//                 }
//                 else if ((r + 1 <= n_row-1)&&(c + 1 > n_col-1)) {
//                     cost[r][c] = cost[r+1][c];
//                 }
//             }
//         }
//         return cost[0][0];
//     }
// };




// Up o down DP


// class Solution {
// public:
//     vector<vector<int>> cost;
//     void fully_initialize_cost(int& n_col, int& n_row) {
//         for (int i = 0; i < n_row; i++) {
//             vector<int> temp;
//             for (int j = 0; j < n_col; j++) {
//                 temp.push_back(-1);
//             }
//             cost.push_back(temp);
//         }
//         return;
//     }

//     int solve(vector<vector<int>>& obstacleGrid, int x, int y, int& n_col, int& n_row) {
//         if ((x>n_col-1)||(y>n_row-1)||(obstacleGrid[y][x] == 1)) {
//             return 0;
//         }
//         if (cost[y][x]!=-1) {
//             return cost[y][x];
//         }
//         if ((x == n_col-1)&&(y == n_row -1)) {
//             return 1;
//         }

//         cost[y][x] = solve(obstacleGrid, x+1, y, n_col, n_row) + solve(obstacleGrid, x, y+1, n_col, n_row);
//         return cost[y][x];
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n_row = obstacleGrid.size();
//         int n_col = obstacleGrid[0].size();
//         fully_initialize_cost(n_col,n_row);
//         return solve(obstacleGrid, 0, 0, n_col, n_row);
//     }
// };





    // void fully_initialize(int& n_col, int& n_row) {
    //     for (int i = n_row-1; i >=0; i--) {
    //         vector<int> temp;
    //         for (int j = n_col-1; j >=0; j--) {
    //             // temp.clear();
    //             temp.push_back(i+j+1);
    //         }
    //         tracker.push_back(temp);
    //     }
    //     for (int i = 0; i < n_row; i++) {
    //         for (int j = 0; j < n_col; j++) {
    //             cout << tracker[i][j] << ",";
    //         }
    //         cout << "\n";
    //     }
    //     return;
    // }




// Brute Force

// class Solution {
// public:
//     int count = 0;
//     void backtrack(vector<vector<int>>& obstacleGrid, int x, int y, int& n_col, int& n_row) {
//         if ((x>n_col-1)||(y>n_row-1)||(obstacleGrid[y][x] == 1)) {
//             return;
//         }
//         if ((x == n_col-1)&&(y == n_row-1)) {
//             count++;
//             return;
//         }
//         backtrack(obstacleGrid,x+1,y,n_col,n_row);
//         backtrack(obstacleGrid,x,y+1,n_col,n_row);
//         return;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n_row = obstacleGrid.size();
//         int n_col = obstacleGrid[0].size();
//         cout << n_row << n_col << "\n";

//         if (obstacleGrid[n_row-1][n_col-1]==1) {
//             return 0;
//         }
//         backtrack(obstacleGrid,0,0,n_col,n_row);
//         return count;
//     }
// };
