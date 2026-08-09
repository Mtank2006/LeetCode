class Solution {
public:
    void format(const string& s, int numRows, int currentRow, int size, string& result) {
        int skip1 = (numRows - 1 - currentRow) * 2;
        int skip2 = ((numRows - 1) * 2) - skip1;
        int i = currentRow;
        if (skip1 == 0) {
            while (i < size) {
                result.push_back(s[i]);
                i += skip2;
            }
            return;
        }
        if (skip2 == 0) {
            while (i < size) {
                result.push_back(s[i]);
                i += skip1;
            }
            return;
        }
        while (i < size) {
            result.push_back(s[i]);
            i += skip1;
            if (i >= size) {
                return;
            }
            result.push_back(s[i]);
            i += skip2;
        }
    }
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string result;
        int size = s.size();
        result.reserve(size);
        for (int i = 0; i < numRows; ++i) {
            format(s, numRows, i, size, result);
        }
        return result;
    }
};

// optimised enough

// class Solution {
// public:
//     void format(const string& s, int numRows, int currentRow, int size, string& result) {
//         int skip1 = (numRows - 1 - currentRow) * 2;
//         int skip2 = ((numRows - 1) * 2) - skip1;
//         int i = currentRow;
//         while (i < size) {
//             if (skip1 != 0) {
//                 result.push_back(s[i]);
//                 i += skip1;
//             }
//             if (i >= size) {
//                 return;
//             }
//             if (skip2 != 0) {
//                 result.push_back(s[i]);
//                 i += skip2;
//             }
//         }
//     }
//     string convert(string s, int numRows) {
//         if (numRows == 1) {
//             return s;
//         }
//         string result;
//         int size = s.size();
//         result.reserve(size);
//         for (int i = 0; i < numRows; ++i) {
//             format(s, numRows, i, size, result);
//         }
//         return result;
//     }
// };

// works but takes more resources

// class Solution {
// public:
//     string result;
//     void format(string s, int numRows, int currentRow, int size) {
//         int skip1 = (numRows - 1 - currentRow) * 2;
//         int skip2 = ((numRows - 1) * 2) - skip1;
//         int i = currentRow;
//         while (i < size) {
//             if (skip1 != 0) {
//                 result.push_back(s[i]);
//             }
//             i += skip1;
//             if (i >= size) {
//                 continue;
//             }
//             if (skip2 != 0) {
//                 result.push_back(s[i]);
//             }
//             i += skip2;
//         }
//     }
//     string convert(string s, int numRows) {
//         if (numRows == 1) {
//             return s;
//         }
//         int size = s.size();
//         for (int i = 0; i < numRows; ++i) {
//             format(s, numRows, i, size);
//         }
//         return result;
//     }
// };
