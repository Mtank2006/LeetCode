// Static check/append


class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int aSize = a.size();
        int bSize = b.size();
        int count = 0;
        std::vector<int> lps(bSize, 0);
        int i = 1;
        int j = 0;
        while (i < bSize) {
            if (b[i] == b[j]) {
                j++;
                lps[i] = j;
                i++;
            }
            else {
                if (j !=0) {
                    j = lps[j-1];
                }
                else {
                    i++;
                }
            }
        }
        std::string repeat = "";
        while (repeat.length() < (bSize)) {
            repeat += a;
            count++;
        }
        repeat += a;
        count++;
        i = 0;
        j = 0;
        while (i < repeat.length()) {
            if (b[j] != repeat[i]) {
                if (j != 0) {
                    j = lps[j-1];
                }
                else {
                    i++;
                }
            }
            else {
                i++;
                j++;
                if (j == bSize) {
                    if (i <= repeat.length() - aSize) {
                        return count - 1;
                    }
                    else {
                        return count;
                    }
                }
            }
        }
        return -1;
    }
};


// Dynamic check/append


// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) {
//         int aSize = a.size();
//         int bSize = b.size();
//         int count = 0;
//         std::vector<int> lps(bSize, 0);
//         int i = 1;
//         int j = 0;
//         while (i < bSize) {
//             if (b[i] == b[j]) {
//                 j++;
//                 lps[i] = j;
//                 i++;
//             }
//             else {
//                 if (j !=0) {
//                     j = lps[j-1];
//                 }
//                 else {
//                     i++;
//                 }
//             }
//         }
//         std::string repeat = "";
//         while (repeat.length() <= (bSize + aSize)) {
//             repeat += a;
//             count++;
//             i = 0;
//             j = 0;
//             while (i < repeat.length()) {
//                 if (b[j] != repeat[i]) {
//                     if (j != 0) {
//                         j = lps[j-1];
//                     }
//                     else {
//                         i++;
//                     }
//                 }
//                 else {
//                     i++;
//                     j++;
//                     if (j == bSize) {
//                         return count;
//                     }
//                 }
//             }
//         }
//         return -1;
//     }
// };


// Brute force


// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) {
//         int aSize = a.size();
//         int bSize = b.size();
//         int count = 0;
//         std::string repeat = "";
//         while (repeat.size() < bSize+(2*aSize)) {
//             repeat += a;
//             count++;
//             if (repeat.contains(b)) {
//                 return count;
//             }
//         }
//         return -1;
//     }
// };
