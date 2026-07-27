// Proper Dynamicization


class Solution {
public:
    int diverge(int n, std::vector<int>& dp) {
        if (n == 0) {
            return 1;
        }
        if (n == -1) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = diverge(n-1,dp) + diverge(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        std::vector<int> dp(n + 1, -1);
        return diverge(n,dp);
    }
};


// Some optimisation


// class Solution {
// public:
//     int diverge(int n) {
//         if (n == 0) {
//             return 1;
//         }
//         if (n == -1) {
//             return 0;
//         }
//         return diverge(n-1) + diverge(n-2);
//     }
//     int climbStairs(int n) {
//         return diverge(n);
//     }
// };


// Without Dynamicization Just Brute Force


// class Solution {
// public:
//     int ways = 0;
//     void diverge(int n) {
//         if (n <= 0) {
//             if (n == 0) {
//                 ways++;
//                 return;
//             }
//             else {
//                 return;
//             }
//         }
//         diverge(n-1);
//         diverge(n-2);
//     }
//     int climbStairs(int n) {
//         diverge(n);
//         return ways;
//     }
// };
