class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        if (size == 0) {
            return true;
        }
        std::vector<int> lps(size, 0);
        int i = 1;
        int j = 0;
        while (i < size) {
            if (s[i] == s[j]) {
                j++;
                lps[i] = j;
                i++;
            }
            else {
                if (j != 0) {
                    j = lps[j-1];
                }
                else {
                    i++;
                }
            }
        }
        if (lps[size-1] == 0) {
            return false;
        }
        return (size % (size - lps[size-1]) == 0);
    }
};


// Almost all refinement


// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
//         int size = s.size();
//         if (size == 0) {
//             return true;
//         }
//         std::vector<int> lps(size, 0);
//         int i = 1;
//         int j = 0;
//         while (i < size) {
//             if (s[i] == s[j]) {
//                 j++;
//                 lps[i] = j;
//                 i++;
//             }
//             else {
//                 if (j != 0) {
//                     j = lps[j-1];
//                 }
//                 else {
//                     i++;
//                 }
//             }
//         }
//         if (lps[size-1] == 0) {
//             return false;
//         }
//         if (size % (size - lps[size-1]) == 0) {
//             return true;
//         }
//         else {
//             return false;
//         }
//     }
// };


// Runtime Refinement, No if statement improvement


// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
//         int size = s.size();
//         if (size == 0) {
//             return true;
//         }
//         std::vector<int> lps(size, 0);
//         int i = 1;
//         int j = 0;
//         while (i < size) {
//             if (s[i] == s[j]) {
//                 j++;
//                 lps[i] = j;
//                 i++;
//             }
//             else {
//                 if (j != 0) {
//                     j = lps[j-1];
//                 }
//                 else {
//                     i++;
//                 }
//             }
//         }
//         int sub_size = (size - lps[size-1]);
//         if (sub_size == 0 || lps[size-1] == 0) {
//             return false;
//         }
//         if (size % sub_size == 0) {
//             if ((lps[size-1]) % sub_size == 0) {
//                 return true;
//             }
//             else {
//                 return false;
//             }
//         }
//         else {
//             return false;
//         }
//     }
// };


// Un Refined / Extra O(1) mem space and O(n) times max() comparision


// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
//         int size = s.size();
//         if (size == 0) {
//             return true;
//         }
//         std::vector<int> lps(size, 0);
//         int i = 1;
//         int j = 0;
//         int sub_size = 0;
//         while (i < size) {
//             if (s[i] == s[j]) {
//                 sub_size = max(sub_size,i-j);
//                 j++;
//                 lps[i] = j;
//                 i++;
//             }
//             else {
//                 if (j != 0) {
//                     j = lps[j-1];
//                 }
//                 else {
//                     i++;
//                 }
//             }
//         }
//         if (sub_size == 0) {
//             return false;
//         }
//         if (size % sub_size == 0) {
//             if ((sub_size + lps[size-1]) == size) {
//                 return true;
//             }
//             else {
//                 return false;
//             }
//         }
//         else {
//             return false;
//         }
//     }
// };
