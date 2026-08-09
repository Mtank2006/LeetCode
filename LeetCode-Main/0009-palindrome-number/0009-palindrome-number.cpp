class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int reverseHalf = 0;
        while (x > reverseHalf) {
            reverseHalf *= 10;
            reverseHalf += (x % 10);
            x /= 10;
        }
        if (reverseHalf == x || reverseHalf/10 == x) {
            return true;
        }
        return false;
    }
};

// reversing whole integer (not good enough)

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0 || (x % 10 == 0 && x != 0)) {
//             return false;
//         }
//         int digits = 0;
//         int tempx = x;
//         long long reverse = 0;
//         while (tempx > 0) {
//             reverse *= 10;
//             reverse += (tempx % 10);
//             tempx /= 10;
//         }
//         if (reverse == x) {
//             return true;
//         }
//         return false;
//     }
// };

// mehhh solution

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) {
//             return false;
//         }
//         int digits = 0;
//         int tempx = x;
//         while (tempx > 0) {
//             tempx /= 10;
//             digits++;
//         }
//         long long reverse = 0;
//         long long power;
//         while (digits >= 0) {
//             power = pow(10, digits);
//             reverse = reverse*10 + (x % power);
//             digits--;
//         }
//         cout << reverse << "\n";
//         if (reverse == x) {
//             return true;
//         }
//         else {
//             return false;
//         }
//     }
// };

// mehHHH

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) {
//             return false;
//         }
//         int digits = 0;
//         int tempx = x;
//         while (tempx > 0) {
//             tempx /= 10;
//             digits++;
//         }
//         int r = 1;
//         int l = pow(10, digits - 1);
//         cout << digits;
//         while (l < r) {
//             if (x/r != x/l) {
//                 return false;
//             }
//             l /= 10;
//             r *= 10;
//         }
//         return true;
//     }
// };
